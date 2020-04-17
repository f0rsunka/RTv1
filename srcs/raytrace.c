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

t_vec3		get_normal_dir(t_vec3 p, t_vec3 center_sphere)
{
	t_vec3	normal;
	t_vec3	normal_dir;
	
	normal = vec_diff(center_sphere, p);
	normal_dir = vec_normalize(normal);
	return (normal_dir);
}

float		get_count_light(t_closest_sphere closest, t_vec3 dir, t_rtv *r)
{
	t_vec3	p;
	t_vec3	reverse_dir;
	t_vec3	normal_dir;
	float	count_light;

	p = vec_add(r->camera, vec_add_const(dir, closest.dist));
	reverse_dir = vec_add_const(dir, -1);
	normal_dir = get_normal_dir(r->camera, closest.sphere->center);
	// count_light = calculate_lightning(r, dir, normal_dir, closest.sphere->specular, p);
	count_light = calculate_lightning(r, reverse_dir, normal_dir, closest.sphere->specular, p);
	return (count_light);
}

t_color		trace_ray(t_vec3 camera, t_vec3 dir, t_rtv *r)
{
	int					i;
	t_color				total_color;
	t_closest_sphere	closest;
	float				count_light;

	i = 0;
	closest.dist = FLT_MAX;
	closest.sphere = NULL;
	while (i < r->count_objects)
	{
		if (intersect_ray_sphere(camera, dir, r->sphere[i], &closest.dist))
		{
			closest.sphere = &r->sphere[i];
		}
		i++;
	}
	if (closest.sphere == NULL)
		return (transform_color(BACKGROUND_COLOR));
	count_light = get_count_light(closest, dir, r);
	total_color = add_light(closest.sphere->color, count_light);
	return (total_color);
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
