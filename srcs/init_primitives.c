/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitives.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/09 17:19:17 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** WARNING! CYLINDER's equation needs to only one axis is zero. It depends
** on coefficients.
** 
** For example, if cylinder's coefficients is {1.0f, 0.0f, 1.0f}, axis y is zero,
** so cylinder in vertical position.
** 
*/

t_cylinder	*init_cylinder(t_vec3 offset, t_vec3 coef, t_vec3 angle, t_material mat)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	(cylinder == NULL ? rtv_error(MALLOC_ERROR) : 0);
	cylinder->offset = offset;
	cylinder->coef = coef;
	check_coefficients_cyl(cylinder->coef);
	cylinder->angle = angle;
	cylinder->radius = 1.0f;
	check_radius(cylinder->radius);
	cylinder->material.color = float_to_byte((t_color){mat.color.r, mat.color.g, mat.color.b});
	cylinder->material.specular = mat.specular;
	check_specular(cylinder->material.specular);
	return (cylinder);
}

t_cone	*init_cone(t_vec3 offset, t_vec3 coef, t_vec3 angle, t_material mat)
{
	t_cone *cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	(cone == NULL ? rtv_error(MALLOC_ERROR) : 0);
	cone->offset = offset;
	cone->coef = coef;
	check_coefficients_cone(cone->coef);
	cone->angle = angle;
	cone->material.color = float_to_byte((t_color){mat.color.r, mat.color.g, mat.color.b});
	cone->material.specular = mat.specular;
	check_specular(cone->material.specular);
	return (cone);
}

t_plane	*init_plane(t_vec3 offset, t_vec3 coef, t_vec3 normal, t_material mat)
{
	t_plane *plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	(plane == NULL ? rtv_error(MALLOC_ERROR) : 0);
	plane->offset = (t_vec3){offset.x, offset.y, offset.z};
	plane->coef = (t_vec3){coef.x, coef.y, coef.z};
	plane->normal = (t_vec3){normal.x, normal.y, normal.z};
	plane->angle = (t_vec3){0.0f, 0.0f, 0.0f};
	plane->material.color = float_to_byte((t_color){mat.color.r, mat.color.g, mat.color.b});
	plane->material.specular = mat.specular;
	check_specular(plane->material.specular);
	return (plane);
}

t_sphere	*init_sphere(t_vec3 center, float radius, t_vec3 angle, t_material mat)
{
	t_sphere *sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere == NULL ? rtv_error(MALLOC_ERROR) : 0;
	sphere->center = center;
	sphere->radius = radius;
	check_radius(sphere->radius);
	sphere->angle = angle;
	sphere->material.color = float_to_byte((t_color){mat.color.r, mat.color.g, mat.color.b});
	sphere->material.specular = mat.specular;
	check_specular(sphere->material.specular);
	return (sphere);
}

void	init_primitives(t_rtv *r)
{
	int		i;
	t_scene *scene;
	t_scene	*tmp;

	i = 0;
	(COUNT_PRIMITIVES <= 0 ? rtv_error(PRIMITIVES_MIN) : 0);
	(COUNT_PRIMITIVES > 7 ? rtv_error(PRIMITIVES_MAX) : 0);
	while (i < COUNT_PRIMITIVES)
	{
		scene = (t_scene*)malloc(sizeof(t_scene));
		(scene == NULL ? rtv_error(MALLOC_ERROR) : 1);
		if (i == 0)
		{
			scene->object = init_sphere((t_vec3){-3.0, 1.0, -5.0}, 2.0f, (t_vec3){5.0f, 5.0f, 5.0f}, (t_material){(BLUE), 50.0f});
			scene->type = SPHERE;
		}
		if (i == 1)
		{
			scene->object = init_sphere((t_vec3){6.0, 1.0, -4.0}, 2.0f, (t_vec3){0.0f, 0.0f, 0.0f}, (t_material){(PINK), 50.0f});
			scene->type = SPHERE;
		}
		if (i == 2)
		{
			scene->object = init_cylinder((t_vec3){0.0f, 0.0f, -5.0f}, (t_vec3){1.0f, 0.0f, 1.0f}, (t_vec3){0.0f, 0.0f, 45.0f}, (t_material){BRIGHT_PURPLE, 50.0f});
			scene->type = CYLINDER;
		}
		if (i == 3)
		{
			scene->object = init_plane((t_vec3){0.0f, 0.0f, -13.0f}, (t_vec3){0.0f, 0.0f, 1.0f}, (t_vec3){0.0f, 0.0f, 1.0f}, (t_material){ROSE_PINK, 50.0f});
			scene->type = PLANE;
		}
		if (i == 4)
		{
			scene->object = init_plane((t_vec3){0.0f, 3.0f, 0.0f}, (t_vec3){0.0f, 1.0f, 0.0f}, (t_vec3){0.0f, -1.0f, 0.0f}, (t_material){INDEPENDENCE, 50.f});
			scene->type = PLANE;
		}
		if (i == 5)
		{
			scene->object = init_cone((t_vec3){5.0f, -1.0f, -4.0f}, (t_vec3){9.0f, 9.0f, 16.0f}, (t_vec3){0.0f, 0.0f, -50.0f}, (t_material){INDIGO, 50.0f});
			scene->type = CONE;
		}
		if (i == 0)
			scene->next = NULL;
		else
			scene->next = tmp;
		i++;
		tmp = scene;
	}
	r->scene = scene;
}
