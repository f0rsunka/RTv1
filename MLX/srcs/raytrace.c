/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:12:06 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/11 21:12:03 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		cast_ray(t_vec3 camera, t_vec3 dir, t_rtv *r)
{
	int i;

	i = 0;
	while (i < r->count_objects)
	{
		float sphere_dist = FLT_MAX;
		if (intersect_ray_sphere(camera, dir, r->sphere[i], &sphere_dist))
			return (r->sphere[i]->color);
		i++;
	}
	return (BACKGROUND_COLOR);
}

int 		intersect_ray_sphere(t_vec3 camera, t_vec3 point_3d, t_sphere *sphere, float *t0)
{
	t_vec3 C;
	double R;
	t_vec3 OC;
	
	C = sphere->center;
	R = sphere->radius;
	OC = vec_diff(C, camera); //?
	float t = dot_product(OC, point_3d);
	float d2 = dot_product(OC, OC) - t * t;
	if (d2 > R * R)
		return (0);
	float thc = sqrtf(R * R - d2);
	*t0 = t - t;
	float t1 = t + thc;
	if (*t0 < 0)
		*t0 = t1;
	if (*t0 < 0)
		return (0);
	return (1);
}
