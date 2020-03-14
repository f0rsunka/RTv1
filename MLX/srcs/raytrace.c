/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:12:06 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/14 21:41:51 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		cast_ray(t_vec3 camera, t_vec3 dir, t_rtv *r)
{
	int		i;
	float	sphere_dist;

	i = 0;
	while (i < r->count_objects)
	{
		sphere_dist = FLT_MAX;
		if (intersect_ray_sphere(camera, dir, r->sphere[i], &sphere_dist))
		{
			// return (r->sphere[i]->color);
			t_vec3 p = vec_add(camera, vec_add_const(dir, sphere_dist));
			t_vec3 vec_n = vec_diff(p, r->sphere[i]->center); //?
			vec_n = vec_normalize(vec_n);
			return (color_with_light(r->sphere[i]->color, calculate_lightning(r, dir, vec_n)));
		}
		i++;
	}
	return (BACKGROUND_COLOR);
}

int 		intersect_ray_sphere(t_vec3 camera, t_vec3 dir, t_sphere *sphere, float *sphere_dist)
{
	t_vec3	length_cam_center;
	float	t1;
	float	t2;

	length_cam_center = vec_diff(camera, sphere->center);
	if (!calculate_quadratic_equation(length_cam_center, dir, sphere->radius, &t1, &t2))
		return (0);
	if (t1 < *sphere_dist)
		*sphere_dist = t1;
	if (t2 < *sphere_dist)
		*sphere_dist = t2;
	return (1);
}
