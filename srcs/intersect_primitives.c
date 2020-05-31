/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_primitives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:13:57 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/05/31 17:23:11 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int 		intersect_ray_sphere(t_vec3 camera, t_vec3 dir, t_sphere sphere, float *sphere_dist)
{
	t_vec3	length_cam_center;
	float	t1;
	float	t2;

	*sphere_dist = 0.0f;
	length_cam_center = vec_diff(sphere.center, camera);
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
	return (0);
}

int 		intersect_ray_cylinder(t_vec3 camera, t_vec3 dir, t_cylinder cylinder, float *cylinder_dist)
{
	t_vec3	ofs;
	float	t1;
	float	t2;

	*cylinder_dist = 0.0f;
	ofs = vec_diff(camera, cylinder.offset);
	dir.y = 0.0f;
	ofs.y = 0.0f;
	if (!quadratic_equation(ofs, dir, cylinder.radius, &t1, &t2))
		return (0);
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

int		intersect_ray_plane(t_vec3 camera, t_vec3 dir, t_plane plane, float *plane_dist)
{
	float	t;
	t_vec3	ofs;

	ofs = vec_diff(camera, plane.offset);
	t = (plane.coef.x * ofs.x + plane.coef.y * ofs.y + plane.coef.z * ofs.z) / (dir.x * plane.coef.x + dir.y * plane.coef.y + dir.z * plane.coef.z);
	t *= -1;
	if (t >= 0) 
	{
		*plane_dist = t;
		return (1);
	}
	return (0);
}
