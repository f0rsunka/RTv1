/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:15:03 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 12:49:53 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_normal_sphere(t_vec3 p, t_sphere sphere, t_vec3 *normal)
{
	*normal = vec_diff(p, sphere.center);
	rotate(normal, sphere.angle);
}

void		get_normal_cyl(t_ray *ray, float t, t_cylinder cyl)
{
	rotate(&ray->ofs, cyl.angle);
	rotate(&ray->dir, cyl.angle);
	ray->normal.x = ray->ofs.x + ray->dir.x * t;
	ray->normal.y = ray->ofs.y + ray->dir.y * t;
	ray->normal.z = ray->ofs.z + ray->dir.z * t;
	ray->normal = mult_vec(ray->normal, cyl.coef);
}

void		get_normal_cone(t_ray *ray, float t, t_cone cone)
{
	rotate(&ray->ofs, cone.angle);
	rotate(&ray->dir, cone.angle);
	ray->normal.x = ray->ofs.x + ray->dir.x * t;
	ray->normal.y = ray->ofs.y + ray->dir.y * t;
	ray->normal.z = ray->ofs.z + ray->dir.z * t;
}

void		normal(t_close_obj closest, t_rtv *r)
{
	if (closest.type == SPHERE)
		get_normal_sphere(r->ray.p, *((t_sphere *)closest.obj), &r->ray.normal);
	if (closest.type == CYLINDER)
		get_normal_cyl(&r->ray, closest.dist, *((t_cylinder *)closest.obj));
	if (closest.type == CONE)
		get_normal_cone(&r->ray, closest.dist, *((t_cone *)closest.obj));
	if (closest.type == PLANE)
	{
		r->ray.normal = ((t_plane *)closest.obj)->normal;
		rotate(&r->ray.normal, (t_vec3)((t_plane *)closest.obj)->angle);
	}
	r->ray.normal = vec_normalize(r->ray.normal);
}
