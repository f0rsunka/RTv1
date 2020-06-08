/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:14:52 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 01:06:07 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_sphere_0(t_sphere *sphere)
{
	sphere->center = (t_vec3){-3.0, 1.0, -5.0};
	sphere->radius = 2.5f;
	sphere->angle = (t_vec3){5.0f, 5.0f, 5.0f};
	sphere->material.color = float_to_byte(BLUE);
	sphere->material.specular = 50.0f;
}

void	init_sphere_1(t_sphere *sphere)
{
	sphere->center = (t_vec3){6.0, 1.0, -4.0};
	sphere->radius = 2.0f;
	sphere->angle = (t_vec3){0.0f, 0.0f, 0.0f};
	sphere->material.color = float_to_byte(PINK);
	sphere->material.specular = 50.0f;
}

void	init_sphere_2(t_sphere *sphere)
{
	sphere->center = (t_vec3){2.0f, 1.0, -4.0};
	sphere->radius = 1.5f;
	sphere->angle = (t_vec3){0.0f, 0.0f, 0.0f};
	sphere->material.color = float_to_byte(PURPLE);
	sphere->material.specular = 10.0f;
}

void	init_sphere_3(t_sphere *sphere)
{
	sphere->center = (t_vec3){0.0f, -501.0f, 0.0f};
	sphere->radius = 500.0f;
	sphere->material.color = float_to_byte(PURPLE);
	sphere->material.specular = 10.0f;
}

void	init_sphere(int i, t_scene *scene)
{
	scene->object = (t_sphere*)malloc(sizeof(t_sphere));
	(scene->object == NULL ? exit(88) : 14);
	scene->type = SPHERE;
	if (i == 0)
		init_sphere_0((t_sphere *)scene->object);
	if (i == 1)
		init_sphere_1((t_sphere *)scene->object);
}
