/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:12:06 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/12 14:53:30 by f0rsunka         ###   ########.fr       */
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

void		current_type_trace(t_scene *curr, t_close_obj *closest, t_rtv *r)
{
	if (curr->type == TYPE_SPHERE)
		sphere_intersect(r, curr, closest);
	if (curr->type == TYPE_CYLINDER)
		cylinder_intersect(r, curr, closest);
	if (curr->type == TYPE_PLANE)
		plane_intersect(r, curr, closest);
	if (curr->type == TYPE_CONE)
		cone_intersect(r, curr, closest);
}

t_close_obj	trace_ray(t_rtv *r)
{
	t_close_obj		closest;
	t_scene			*tmp;
	t_scene			*current;

	closest_zero(&closest);
	current = r->scene;
	(current == NULL ? exit (88) : 0);
	while (current != NULL)
	{
		current_type_trace(current, &closest, r);
		tmp = current->next;
		current = tmp;
	}
	r->closest = closest;
	if (closest.obj == NULL)
	{
		closest.color = BACKGROUND_COLOR;
		return (closest);
	}
	else
		closest.color = calculate_lightning(r, closest);
	return (closest);
}
