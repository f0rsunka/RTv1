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

t_vec3	calculate_reflect_ray(t_vec3 r, t_vec3 normal)
{
	float	dot_n_r;
	t_vec3	reflect_ray;

	dot_n_r = dot_product(r, normal);
	reflect_ray = vec_diff(r, mult_vec_const(mult_vec_const(normal, 2), dot_n_r));
	return (reflect_ray);
}

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

t_collision		trace_ray(t_rtv *r)
{
	t_collision			collision;
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
	collision.obj = closest.obj;
	if (closest.obj == NULL)
	{
		collision.col = BACKGROUND_COLOR;
		return (collision);
	}
	collision.col = calculate_lightning(r, closest);
	return (collision);
}
