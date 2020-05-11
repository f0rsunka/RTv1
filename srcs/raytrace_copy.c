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

int		sphere_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest)
{
	float				intersect_res;
	float				tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = intersect_ray_sphere(r->trace.from, r->trace.to, *(t_sphere *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_sphere *)current->object;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

t_color		trace_ray(t_rtv *r)
{
	t_color				color;
	t_closest_obj		closest;
	t_scene				*tmp;
	t_scene				*current;

	closest.dist = FLT_MAX;
	closest.obj = NULL;
	current = r->scene;
	while (current != NULL)
	{
		if (current->type == SPHERE)
		{
			sphere_intersect(r, current, &closest);
		}
		tmp = current->next;
		current = tmp;
	}
	if (closest.obj == NULL)
	{
		return (BACKGROUND_COLOR);
	}
	color = calculate_lightning(r, closest);
	// if (depth <= 0 || ((t_sphere *)closest.obj)->material.reflective <= 0)
	// 	return (color);
	// reflect_ray = calculate_reflect_ray();
	// reflected_color = TraceRay(P, R, 0.001, inf, depth - 1);
	return (color);
	// color = ((t_sphere *)closest.obj)->material.color;
}
