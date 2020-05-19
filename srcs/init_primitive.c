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

void	init_place(t_scene *scene)
{
	scene->type = PLACE;
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
		if (i == 1) // && i <= 2)
			init_sphere(i, scene);
		// if (i == 3)
		// 	init_place(scene);
		// if (i == 4)
		// 	init_cone(scene);
		if (i == 0)
			init_cylinder(scene);
		if (i == 0)
			scene->next = NULL;
		else
			scene->next = tmp;
		i++;
		tmp = scene;
	}
	r->scene = scene;
}
