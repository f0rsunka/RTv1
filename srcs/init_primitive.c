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
	scene->object = (t_object *)malloc(sizeof(t_object));
	scene->object == NULL ? exit(88) : 0;
	((t_object *)scene->object)->radius = 1.0f;
	((t_object *)scene->object)->offset = (t_vec3){2.0f, 0.0f, -5.0f};
	((t_object *)scene->object)->material.color = float_to_byte(BRIGHT_PURPLE);
	((t_object *)scene->object)->material.specular = 50.0f;
	scene->type = CYLINDER;
}

void	init_cone(t_scene *scene)
{
	scene->object = (t_object *)malloc(sizeof(t_object));
	scene->object == NULL ? exit(88) : 0;
	((t_object *)scene->object)->material.color = float_to_byte(BRIGHT_PURPLE);
	((t_object *)scene->object)->material.specular = 50.0f;
	scene->type = CONE;
}
