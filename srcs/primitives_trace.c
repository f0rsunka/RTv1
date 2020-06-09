/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives_trace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:13:57 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 12:19:13 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			is_sphere(t_vec3 camera, t_vec3 dir, t_sphere sphere,
															float *sphere_dist)
{
	t_coefficients	c;
	float			d;
	t_vec3			length_cam_center;
	float			t1;
	float			t2;

	*sphere_dist = 0.0f;
	length_cam_center = vec_diff(camera, sphere.center);
	rotate(&dir, sphere.angle);
	rotate(&length_cam_center, sphere.angle);
	sphere_calc_coefficients(&c, length_cam_center, dir, sphere.radius);
	d = calc_discriminant(c.a, c.b, c.c);
	if (d < 0)
		return (0);
	t1 = (-c.b + sqrtf(d)) / (2 * c.a);
	t2 = (-c.b - sqrtf(d)) / (2 * c.a);
	return (is_sqrt_valide(t1, t2, sphere_dist));
}

int			is_cylinder(t_vec3 camera, t_vec3 dir, t_cylinder cylinder,
														float *cylinder_dist)
{
	t_vec3			ofs;
	t_coefficients	c;
	float			d;
	float			t1;
	float			t2;

	*cylinder_dist = 0.0f;
	ofs = vec_diff(camera, cylinder.offset);
	rotate(&dir, cylinder.angle);
	rotate(&ofs, cylinder.angle);
	cylinder_calc_coefficients(&c, ofs, dir, cylinder);
	d = calc_discriminant(c.a, c.b, c.c);
	if (d < 0)
		return (0);
	t1 = (-c.b + sqrtf(d)) / (2 * c.a);
	t2 = (-c.b - sqrtf(d)) / (2 * c.a);
	return (is_sqrt_valide(t1, t2, cylinder_dist));
}

int			is_plane(t_vec3 camera, t_vec3 dir, t_plane plane,
														float *plane_dist)
{
	float	t;
	t_vec3	ofs;

	*plane_dist = 0.0f;
	ofs = vec_diff(camera, plane.offset);
	rotate(&dir, plane.angle);
	rotate(&ofs, plane.angle);
	t = (plane.coef.x * ofs.x + plane.coef.y * ofs.y + plane.coef.z * ofs.z) /
		(dir.x * plane.coef.x + dir.y * plane.coef.y + dir.z * plane.coef.z);
	t *= -1;
	if (t > 0)
	{
		*plane_dist = t;
		return (1);
	}
	return (0);
}

int			is_cone(t_vec3 camera, t_vec3 dir, t_cone cone, float *cone_dist)
{
	t_vec3			ofs;
	t_coefficients	c;
	float			d;
	float			t1;
	float			t2;

	*cone_dist = 0.0f;
	ofs = vec_diff(camera, cone.offset);
	rotate(&dir, cone.angle);
	rotate(&ofs, cone.angle);
	cone_calc_coefficients(&c, ofs, dir, cone);
	d = calc_discriminant(c.a, c.b, c.c);
	if (d < 0)
		return (0);
	t1 = (-c.b + sqrtf(d)) / (2 * c.a);
	t2 = (-c.b - sqrtf(d)) / (2 * c.a);
	return (is_sqrt_valide(t1, t2, cone_dist));
}
