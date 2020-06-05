/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:15:03 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/04 21:12:22 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_normal_sphere(t_vec3 p, t_vec3 center_sphere, t_vec3 *normal)
{
	*normal = vec_diff(p, center_sphere);
	// *normal = vec_diff(center_sphere, p);
}

void		get_normal_cylinder(t_vec3 p, t_vec3 offset, t_vec3 *normal)
{
	*normal = vec_diff(p, offset);
	normal->y = 0.0f;
}

void		normal(t_closest_obj closest, t_rtv *r)
{
	if (closest.type == SPHERE)
		get_normal_sphere(r->ray.p, ((t_sphere *)closest.obj)->center, &r->ray.normal);
	if (closest.type == CYLINDER)
		get_normal_cylinder(r->ray.p, ((t_cylinder *)closest.obj)->offset, &r->ray.normal);
	if (closest.type == PLANE)
		r->ray.normal = ((t_plane *)closest.obj)->normal;
		// r->ray.normal = mult_vec_const(((t_plane *)closest.obj)->normal, -1);
	r->ray.normal = vec_normalize(r->ray.normal);
}
