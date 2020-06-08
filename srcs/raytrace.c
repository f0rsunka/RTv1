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

int				sphere_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest)
{
	int	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = intersect_ray_sphere(r->trace.from, r->trace.to, *(t_object *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_object *)current->object;
		closest->type = SPHERE;
		closest->mat = ((t_object *)closest->obj)->material;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int				cylinder_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest)
{
	int	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = intersect_ray_cylinder(mult_vec_const(r->trace.from, -1), r->trace.to, *(t_object *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_object *)current->object;
		closest->type = CYLINDER;
		closest->mat = ((t_object *)closest->obj)->material;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int				cone_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest)
{
	int	intersect_res;
	float	tmp_dist;
   
	tmp_dist = 0.0f;
	// intersect_res = intersect_ray_cone(mult_vec_const(r->trace.from, -1), r->trace.to, (t_cone *)current->object, &tmp_dist);
	intersect_res = intersect_ray_cone(r->trace.from, r->trace.to, (t_cone *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min)
	{
	// printf("%d\n", intersect_res);
		closest->dist = tmp_dist;
		closest->obj = (t_cone *)current->object;
		closest->type = CONE;
		closest->mat = ((t_cone *)closest->obj)->material;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int				plane_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = intersect_ray_plane(r->trace.from, r->trace.to, *(t_object *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_object *)current->object;
		closest->type = PLANE;
		closest->mat = ((t_object *)closest->obj)->material;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

t_closest_obj	trace_ray(t_rtv *r)
{
	t_closest_obj		closest;
	t_scene				*tmp;
	t_scene				*current;

	closest_zero(&closest);
	current = r->scene;
	(current == NULL ? exit (88) : 0);
	while (current != NULL)
	{
		if (current->type == SPHERE)
		{
			sphere_intersect(r, current, &closest);
		}
		if (current->type == CYLINDER)
		{
			cylinder_intersect(r, current, &closest);
		}
		if (current->type == CONE)
		{
			cone_intersect(r, current, &closest);
		}
		if (current->type == PLANE)
		{
			plane_intersect(r, current, &closest);
		}
		tmp = current->next;
		current = tmp;
	}
	if (closest.obj == NULL)
	{
		closest.color = BACKGROUND_COLOR;
		return (closest);
	}
	// if (closest.type == CONE)
	// {
	// 	closest.color = ((t_cone *)closest.obj)->material.color;
	// 	return (closest);
	// }
	closest.color = calculate_lightning(r, closest);
	return (closest);
}
