/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_primitives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 21:23:25 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 12:42:45 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		is_intersect(float intersect, float tmp_dist, float closest_dist,
																t_trace trace)
{
	if (intersect && tmp_dist < closest_dist &&
				tmp_dist > trace.dist_min && tmp_dist < trace.dist_max)
		return (1);
	else
		return (0);
}

int		sphere_intersect(t_rtv *r, t_scene *curr, t_close_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = is_sphere(r->trace.from, r->trace.to,
										*(t_sphere *)curr->object, &tmp_dist);
	if (is_intersect(intersect_res, tmp_dist, closest->dist, r->trace))
	{
		closest->dist = tmp_dist;
		closest->obj = (t_sphere *)curr->object;
		closest->mat = ((t_sphere *)closest->obj)->material;
		closest->type = SPHERE;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int		cylinder_intersect(t_rtv *r, t_scene *curr, t_close_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = is_cylinder(r->trace.from, r->trace.to,
										*(t_cylinder *)curr->object, &tmp_dist);
	if (is_intersect(intersect_res, tmp_dist, closest->dist, r->trace))
	{
		closest->dist = tmp_dist;
		closest->obj = (t_cylinder *)curr->object;
		closest->mat = ((t_cylinder *)closest->obj)->material;
		r->ray.ofs = vec_diff(r->camera, ((t_cylinder *)closest->obj)->offset);
		closest->type = CYLINDER;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int		plane_intersect(t_rtv *r, t_scene *curr, t_close_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = is_plane(r->trace.from, r->trace.to,
										*(t_plane *)curr->object, &tmp_dist);
	if (is_intersect(intersect_res, tmp_dist, closest->dist, r->trace))
	{
		closest->dist = tmp_dist;
		closest->obj = (t_plane *)curr->object;
		closest->mat = ((t_plane *)closest->obj)->material;
		r->ray.ofs = vec_diff(r->camera, ((t_plane *)closest->obj)->offset);
		closest->type = PLANE;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}

int		cone_intersect(t_rtv *r, t_scene *curr, t_close_obj *closest)
{
	float	intersect_res;
	float	tmp_dist;

	tmp_dist = 0.0f;
	intersect_res = is_cone(r->trace.from, r->trace.to,
										*(t_cone *)curr->object, &tmp_dist);
	if (is_intersect(intersect_res, tmp_dist, closest->dist, r->trace))
	{
		closest->dist = tmp_dist;
		closest->obj = (t_cone *)curr->object;
		closest->mat = ((t_cone *)closest->obj)->material;
		r->ray.ofs = vec_diff(r->camera, ((t_cone *)closest->obj)->offset);
		closest->type = CONE;
	}
	if (closest->obj == NULL)
		return (0);
	else
		return (1);
}
