/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives_trace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:13:57 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/08 23:00:19 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int 		is_sphere(t_vec3 camera, t_vec3 dir, t_sphere sphere, float *sphere_dist)
{
	t_vec3	length_cam_center;
	float	t1;
	float	t2;

	rotate(&dir, sphere.angle);
	*sphere_dist = 0.0f;
	length_cam_center = vec_diff(camera, sphere.center);
	rotate(&length_cam_center, sphere.angle);
	if (!quadratic_equation(length_cam_center, dir, sphere.radius, &t1, &t2))
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
	if (t1 > 0 && t2 < 0)
	{
		*sphere_dist = t1;
		return (1);
	}
	if (t2 > 0 && t1 < 0)
	{
		*sphere_dist = t2;
		return (1);
	}
	return (0);
}

int 		is_cylinder(t_vec3 camera, t_vec3 dir, t_cylinder cylinder, float *cylinder_dist)
{
	t_vec3			ofs;
	t_coefficients	c;
	float			d;
	float			t1;
	float			t2;

	rotate(&dir, cylinder.angle);
	*cylinder_dist = 0.0f;
	ofs = vec_diff(camera, cylinder.offset);
	rotate(&ofs, cylinder.angle);
	c.a = cylinder.coef.x * (dir.x * dir.x) + cylinder.coef.y * (dir.y * dir.y) + cylinder.coef.z * (dir.z * dir.z);
	c.b = 2 * (cylinder.coef.x * (ofs.x * dir.x) + cylinder.coef.y * (ofs.y * dir.y) + cylinder.coef.z * (ofs.z * dir.z));
	c.c = cylinder.coef.x * (ofs.x * ofs.x) + cylinder.coef.y * (ofs.y * ofs.y) + cylinder.coef.z * (ofs.z * ofs.z) - cylinder.radius;
	d = calc_discriminant(c.a, c.b, c.c);
	if (d < 0)
		return (0);
	t1 = (- c.b + sqrtf(d)) / (2 * c.a);
	t2 = (- c.b - sqrtf(d)) / (2 * c.a);
	if (t1 > 0 && t2 < 0)
	{
		*cylinder_dist = t1;
		return (1);
	}
	if (t2 > 0 && t1 < 0)
	{
		*cylinder_dist = t2;
		return (1);
	}
	if (t1 < t2 && t1 >= 0)
	{
		*cylinder_dist = t1;
		return (1);
	}
	if (t2 < t1 && t2 >= 0)
	{
		*cylinder_dist = t2;
		return (1);
	}
	return (0);
}

int		is_plane(t_vec3 camera, t_vec3 dir, t_plane plane, float *plane_dist)
{
	float	t;
	t_vec3	ofs;

	rotate(&dir, plane.angle);
	*plane_dist = 0.0f;
	ofs = vec_diff(camera, plane.offset);
	rotate(&ofs, plane.angle);
	t = -1 * (plane.coef.x * ofs.x + plane.coef.y * ofs.y + plane.coef.z * ofs.z) / (dir.x * plane.coef.x + dir.y * plane.coef.y + dir.z * plane.coef.z);
	if (t > 0) 
	{
		*plane_dist = t;
		return (1);
	}
	return (0);
}

int		is_cone(t_vec3 camera, t_vec3 dir, t_cone cone, float *cone_dist)
{
	t_vec3			ofs;
	t_coefficients	c;
	float			d;
	float			t1;
	float			t2;

	rotate(&dir, cone.angle);
	*cone_dist = 0.0f;
	ofs = vec_diff(camera, cone.offset);
	rotate(&ofs, cone.angle);

	//					Z AXIS   						//
	// c.a = dir.x * dir.x + dir.y * dir.y - dir.z * dir.z;
	// c.b = 2 * (ofs.x * dir.x + ofs.y * dir.y - ofs.z * dir.z);
	// c.c = ofs.x * ofs.x + ofs.y * ofs.y - ofs.z * ofs.z;
	//												//
	

	//					Y AXIS   						//
	// c.a = dir.x * dir.x - dir.y * dir.y + dir.z * dir.z;
	// c.b = 2 * (ofs.x * dir.x - ofs.y * dir.y + ofs.z * dir.z);
	// c.c = ofs.x * ofs.x - ofs.y * ofs.y + ofs.z * ofs.z;
	//												//



	c.a = (dir.x * dir.x) / cone.coef.x - (dir.y * dir.y) / cone.coef.y + (dir.z * dir.z) / cone.coef.z;
	c.b = 2 * ((ofs.x * dir.x) / cone.coef.x - (ofs.y * dir.y) / cone.coef.y + (ofs.z * dir.z) / cone.coef.z);
	c.c = (ofs.x * ofs.x) / cone.coef.x - (ofs.y * ofs.y) / cone.coef.y + (ofs.z * ofs.z) / cone.coef.z;
	
	d = calc_discriminant(c.a, c.b, c.c);
	if (d < 0)
		return (0);
	t1 = (- c.b + sqrtf(d)) / (2 * c.a);
	t2 = (- c.b - sqrtf(d)) / (2 * c.a);
	
	if (t1 > 0 && t2 < 0)
	{
		*cone_dist = t1;
		return (1);
	}
	if (t2 > 0 && t1 < 0)
	{
		*cone_dist = t2;
		return (1);
	}
	if (t1 < t2 && t1 >= 0)
	{
		*cone_dist = t1;
		return (1);
	}
	if (t2 < t1 && t2 >= 0)
	{
		*cone_dist = t2;
		return (1);
	}
	return (0);
}
