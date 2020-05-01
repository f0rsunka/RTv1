/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:19:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/13 20:37:30 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


int 		intersect_ray_sphere_shadow(t_vec3 camera, t_vec3 dir, t_sphere sphere, float *sphere_dist)
{
	t_vec3	length_cam_center;
	float	t1;
	float	t2;

	*sphere_dist = 0.001f;
	length_cam_center = vec_diff(camera, sphere.center);
	if (!calculate_quadratic_equation(length_cam_center, dir, sphere.radius, &t1, &t2))
		return (0);
	if (t1 < t2 && t1 >= 0)
	{
		*sphere_dist = t1;
		return (1);
	}
	if (t2 < t1 && t2 >= 0)
	{
		*sphere_dist = t2;
		return (1);
	}
	return (0);
}

int		shadow_ray(t_rtv *r, t_vec3 light_dir, t_scene *current, t_closest_obj *closest)
{
	float				intersect_res;
	float				tmp_dist;

	tmp_dist = 0.001f;
	intersect_res = intersect_ray_sphere_shadow(r->ray.p, light_dir, *(t_sphere *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > 0.001)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_sphere *)current->object;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int		is_shadow(t_rtv *r, t_vec3 light_dir)
{
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
			shadow_ray(r, light_dir, current, &closest);
		}
		tmp = current->next;
		current = tmp;
	}
	if (closest.obj == NULL)
		return (0);
	return (1);
}
