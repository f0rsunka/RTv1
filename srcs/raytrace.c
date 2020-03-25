/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:12:06 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 15:35:41 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** vec_add_const(dir, sphere_dist) - получаем реальное расстояние от
** вектора направления до точки в трехмерной системе координат
**
** vec_add - складываем расстояние до точки в т.с.к. с координатами камеры,
** чтобы отрисовка менялась с учетом местоположения камеры
*/

t_vec3		get_normal_dir(t_vec3 camera, t_vec3 center_sphere, float sphere_dist, t_vec3 dir)
{
	t_vec3	p;
	t_vec3	normal;
	t_vec3	normal_dir;
	
	p = vec_add(camera, vec_add_const(dir, sphere_dist));
	normal = vec_diff(center_sphere, p);
	normal_dir = vec_normalize(normal);
	return (normal_dir);
}

t_color		trace_ray(t_vec3 camera, t_vec3 dir, t_rtv *r)
{
	int					i;
	float				sphere_dist;
	t_vec3				normal_dir;
	t_color				total_light;
	// t_sphere			*closest_sphere;
	t_closest_sphere	closest;

	i = 0;
	// closest.sphere = NULL;
	while (i < r->count_objects)
	{
		closest.dist = FLT_MAX;
		if (intersect_ray_sphere(camera, dir, r->sphere[i], &closest.dist))
		{
			// return (r->sphere[i].color);
			// closest.sphere = &r->sphere[i];
			normal_dir = get_normal_dir(camera, r->sphere[i].center, closest.dist, dir);
			total_light = add_light(r->sphere[i].color, calculate_lightning(r, dir, normal_dir, r->sphere[i].specular));
			return (total_light);
		}
		i++;
	}
	// if (closest.sphere == NULL)
		return (BACKGROUND_COLOR);
	// else
	// {
	// 	normal_dir = get_normal_dir(camera, closest.sphere->center, closest.dist, dir);
	// 	total_light = add_light(closest.sphere->color, calculate_lightning(r, dir, normal_dir));
	// 	return (total_light);
	// }
}

int 		intersect_ray_sphere(t_vec3 camera, t_vec3 dir, t_sphere sphere, float *sphere_dist)
{
	t_vec3	length_cam_center;
	float	t1;
	float	t2;

	length_cam_center = vec_diff(camera, sphere.center);
	if (!calculate_quadratic_equation(length_cam_center, dir, sphere.radius, &t1, &t2))
		return (0);
	if (t1 < *sphere_dist && t1 >= 0)
	{
		*sphere_dist = t1;
		return (1);
	}
	if (t2 < *sphere_dist && t2 >= 0)
	{
		*sphere_dist = t2;
		return (1);
	}
	return (0);
}
