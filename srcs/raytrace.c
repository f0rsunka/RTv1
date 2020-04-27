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


// Ошибка в том, что где-то неверно стоит указатель. Свет есть только на сфере, которая инициализирована последней.

int		sphere_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest)
{
	float				intersect_res;
	float				tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = intersect_ray_sphere(r->camera, r->ray.dir, *(t_sphere *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist)
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
			if (sphere_intersect(r, current, &closest) == 1)
				color = calculate_lightning(r, closest);
		}
		tmp = current->next;
		current = tmp;
	}
	if (closest.obj == NULL)
		return (float_to_byte(BACKGROUND_COLOR));
	// color = calculate_lightning(r, closest);
	return (color);
}
