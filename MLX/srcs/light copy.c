/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:36:57 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/13 21:06:10 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		cast_ray(t_vec3 camera, t_vec3 dir, t_rtv *r)
{
	int		i;
	int		j;
	float	sphere_dist;
	t_vec3	light_dir;
	float	diffuse_light_intensity;

	i = 0;
	while (i < r->count_objects)
	{
		sphere_dist = FLT_MAX;
		if (intersect_ray_sphere(camera, dir, r->sphere[i], &sphere_dist))
			return (r->sphere[i]->color);
		j = 0;
		whlie (j < r->count_lights)
		{
			light_dir = vec_normalize(vec_diff(r->light.position, sphere_dist));
			diffuse_light_intensity += r->light.intensity * light_dir; //?
			j++;
		}
		i++;
	}
	return (BACKGROUND_COLOR);
}
