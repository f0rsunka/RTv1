/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_primitives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 21:23:25 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/07 16:14:15 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				sphere_intersect(t_rtv *r, t_scene *current, t_close_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = is_sphere(r->trace.from, r->trace.to, *(t_sphere *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min && tmp_dist < r->trace.dist_max)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_sphere *)current->object;
		closest->mat = ((t_sphere *)closest->obj)->material;
		closest->type = SPHERE;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int				cylinder_intersect(t_rtv *r, t_scene *current, t_close_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = is_cylinder(r->trace.from, r->trace.to, *(t_cylinder *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min && tmp_dist < r->trace.dist_max)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_cylinder *)current->object;
		closest->mat = ((t_cylinder *)closest->obj)->material;
		closest->type = CYLINDER;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int				plane_intersect(t_rtv *r, t_scene *current, t_close_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = is_plane(r->trace.from, r->trace.to, *(t_plane *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min && tmp_dist < r->trace.dist_max)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_plane *)current->object;
		closest->mat = ((t_plane *)closest->obj)->material;
		closest->type = PLANE;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int				cone_intersect(t_rtv *r, t_scene *current, t_close_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = is_cone(r->trace.from, r->trace.to, *(t_cone *)current->object, &tmp_dist);
	if (intersect_res && tmp_dist < closest->dist && tmp_dist > r->trace.dist_min && tmp_dist < r->trace.dist_max)
	{
		closest->dist = tmp_dist;
		closest->obj = (t_cone *)current->object;
		closest->mat = ((t_cone *)closest->obj)->material;
		closest->type = CONE;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}
