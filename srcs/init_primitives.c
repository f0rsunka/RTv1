/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitives.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/09 00:37:40 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_cylinder(t_scene *scene)
{
	scene->object = (t_cylinder *)malloc(sizeof(t_cylinder));
	scene->object == NULL ? exit(88) : 0;
	((t_cylinder *)scene->object)->radius = 1.0f;
	((t_cylinder *)scene->object)->offset = (t_vec3){0.0f, 0.0f, -5.0f};
	((t_cylinder *)scene->object)->coef = (t_vec3){1.0f, 0.0f, 1.0f};
	((t_cylinder *)scene->object)->angle = (t_vec3){0.0f, 0.0f, 45.0f};
	((t_cylinder *)scene->object)->material.color = float_to_byte(BRIGHT_PURPLE);
	((t_cylinder *)scene->object)->material.specular = 50.0f;
	scene->type = TYPE_CYLINDER;
}


/**			FORMULA WITHOUT DELIM			 **/

// void	init_cone(t_scene *scene)
// {
// 	scene->object = (t_cone *)malloc(sizeof(t_cone));
// 	scene->object == NULL ? exit(88) : 0;
// 	((t_cone *)scene->object)->offset = (t_vec3){5.0f, 1.0f, 5.0f};
// 	((t_cone *)scene->object)->coef = (t_vec3){4.0f, 4.0f, 121.0f};
// 	((t_cone *)scene->object)->material.color = float_to_byte(BRIGHT_PURPLE);
// 	((t_cone *)scene->object)->material.specular = 50.0f;
// 	scene->type = TYPE_CONE;
// }



/**			FORMULA WITH DELIM			**/


void	init_cone(t_scene *scene)
{
	scene->object = (t_cone *)malloc(sizeof(t_cone));
	scene->object == NULL ? exit(88) : 0;
	((t_cone *)scene->object)->offset = (t_vec3){5.0f, -1.0f, -4.0f};
	((t_cone *)scene->object)->coef = (t_vec3){9.0f, 9.0f, 16.0f};
	((t_cone *)scene->object)->angle = (t_vec3){0.0f, 0.0f, -50.0f};
	((t_cone *)scene->object)->material.color = float_to_byte(INDIGO);
	((t_cone *)scene->object)->material.specular = 50.0f;
	scene->type = TYPE_CONE;
}

t_plane	*init_plane(t_vec3 offset, t_vec3 coef, t_vec3 normal, t_color color)
{
	t_plane *plane;
	
	plane = (t_plane *)malloc(sizeof(t_plane));
	plane == NULL ? exit(88) : 0;
	plane->offset = (t_vec3){offset.x, offset.y, offset.z};
	plane->coef = (t_vec3){coef.x, coef.y, coef.z};
	plane->normal = (t_vec3){normal.x, normal.y, normal.z};
	plane->angle = (t_vec3){0.0f, 0.0f, 0.0f};
	plane->material.color = float_to_byte((t_color){color.r, color.g, color.b});
	plane->material.specular = 50.0f;
	return (plane);
}
