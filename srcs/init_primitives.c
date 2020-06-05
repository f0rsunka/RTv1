/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitives.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/05 14:16:26 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_cylinder(t_scene *scene)
{
	scene->object = (t_cylinder *)malloc(sizeof(t_cylinder));
	scene->object == NULL ? exit(88) : 0;
	((t_cylinder *)scene->object)->radius = 1.0f;
	((t_cylinder *)scene->object)->offset = (t_vec3){2.0f, 0.0f, -5.0f};
	((t_cylinder *)scene->object)->material.color = float_to_byte(BRIGHT_PURPLE);
	((t_cylinder *)scene->object)->material.specular = 50.0f;
	scene->type = CYLINDER;
}

void	init_cone(t_scene *scene)
{
	scene->object = (t_cone *)malloc(sizeof(t_cone));
	scene->object == NULL ? exit(88) : 0;
	((t_cone *)scene->object)->material.color = float_to_byte(BRIGHT_PURPLE);
	((t_cone *)scene->object)->material.specular = 50.0f;
	scene->type = CONE;
}

t_plane	*init_plane(t_vec3 offset, t_vec3 coef, t_vec3 normal, t_color color)
{
	t_plane *plane;
	
	plane = (t_plane *)malloc(sizeof(t_plane));
	plane == NULL ? exit(88) : 0;
	plane->offset = (t_vec3){offset.x, offset.y, offset.z};
	plane->coef = (t_vec3){coef.x, coef.y, coef.z};
	plane->normal = (t_vec3){normal.x, normal.y, normal.z};
	plane->material.color = float_to_byte((t_color){color.r, color.g, color.b});
	plane->material.specular = 50.0f;
	return (plane);
}

void	init_primitives(t_rtv *r)
{
	int		i;
	t_scene *scene;
	t_scene	*tmp;

	i = 0;
	while (i < COUNT_PRIMITIVE)
	{
		scene = (t_scene*)malloc(sizeof(t_scene));
		(scene == NULL ? exit(8) : 1);
		if (i >= 0 && i <= 1)
			init_sphere(i, scene);
		if (i == 2)
			init_cylinder(scene);

		if (i == 3)
		{
			scene->object = init_plane((t_vec3){0.0f, 0.0f, -13.0f}, (t_vec3){0.0f, 0.0f, 1.0f}, (t_vec3){0.0f, 0.0f, 1.0f}, (t_color)ROSE_PINK);
			scene->type = PLANE;
		}
		if (i == 4)
		{
			scene->object = init_plane((t_vec3){0.0f, 3.0f, 0.0f}, (t_vec3){0.0f, 1.0f, 0.0f}, (t_vec3){0.0f, -1.0f, 0.0f}, (t_color)INDEPENDENCE);
			scene->type = PLANE;
		}


		// if (i == 5)
		// 	init_cone(scene);
		if (i == 0)
			scene->next = NULL;
		else
			scene->next = tmp;
		i++;
		tmp = scene;
	}
	r->scene = scene;
}
