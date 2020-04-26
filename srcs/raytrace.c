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

t_color		trace_ray(t_vec3 camera, t_vec3 dir, t_rtv *r)
{
	t_color				color;
	t_closest_sphere	closest;
	t_scene				*start_list;
	t_scene				*tmp;
	float				tmp_dist;
	float				intersect_res;

	closest.dist = FLT_MAX;
	tmp_dist = FLT_MAX - 1;
	closest.sphere = NULL;
	start_list = r->scene;
			// tmp_dist = 0.0f;
	while (tmp != NULL)
	{
		if (r->scene->type == SPHERE)
		{
			intersect_res = intersect_ray_sphere(camera, dir, *(t_sphere *)r->scene->object, &tmp_dist);
			if (intersect_res && tmp_dist < closest.dist)
			{
				closest.dist = tmp_dist;
				closest.sphere = (t_sphere *)r->scene->object;
				// r->scene = start_list;
				// color = add_light(closest.sphere->material.color, closest, dir, r);
				// return (color);
			}
		}
		tmp = r->scene->next;
		r->scene = tmp;
	}
	r->scene = start_list;
	if (closest.sphere == NULL)
		return (transform_color(BACKGROUND_COLOR));
	// color = add_light(closest.sphere->material.color, closest, dir, r);
	// color = (t_color){closest.dist / 255, closest.dist / 255, closest.dist / 255};
	color = closest.sphere->material.color;
	return (color);
}

// int		scene_intersect()
// {

// }
