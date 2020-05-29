/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 17:51:27 by cvernius         ###   ########.fr       */
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

void	init_plane(t_scene *scene, t_vec3 center, t_vec3 normal, t_color color)
{
	scene->object = (t_plane *)malloc(sizeof(t_plane));
	scene->object == NULL ? exit(88) : 0;
	((t_plane *)scene->object)->center = (t_vec3){center.x, center.y, center.z};
	((t_plane *)scene->object)->normal = (t_vec3){normal.x, normal.y, normal.z};
	((t_plane *)scene->object)->material.color = float_to_byte((t_color){color.r, color.g, color.b});
	((t_plane *)scene->object)->material.specular = 50.0f;
	scene->type = PLANE;
}

void	init_primitive(t_rtv *r)
{
	int		i;
	t_scene *scene;
	t_scene	*tmp;

	i = 0;
	while (i < COUNT_PRIMITIVE)
	{
		scene = (t_scene*)malloc(sizeof(t_scene));
		(scene == NULL ? exit(8) : 1);
		if (i == 0)
            init_sphere(i, scene);
		if (i == 1)
		    init_plane(scene, (t_vec3){0,-1,0}, (t_vec3){0,1,0}, (t_color){255, 0, 0});
        if (i == 2)
            init_plane(scene, (t_vec3){1,0,0}, (t_vec3){-1,0,0}, (t_color){0, 255, 0});
        if (i == 3)
            init_plane(scene, (t_vec3){-1,0,0}, (t_vec3){1,0,0}, (t_color){0, 0, 255});
//		if (i >= 1 && i <= 2)
//			init_sphere(i, scene);
//		if (i == 3)
//			init_plane(scene);
//		// if (i == 4)
//		// 	init_cone(scene);
//		if (i == 0)
//			init_cylinder(scene);

		if (i == 0)
			scene->next = NULL;
		else
			scene->next = tmp;
		i++;
		tmp = scene;
	}
	r->scene = scene;
}
