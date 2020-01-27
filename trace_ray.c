/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:29:49 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/27 22:13:58 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector2d intersect_ray_sphere(t_vector3d *camera, t_vector3d *D, t_sphere *sphere)
{
	t_vector2d res;
	t_vector3d *C;
	double R;
	t_vector3d *Cam_C;
	double k1;
	double k2;
	double k3;
	double discriminant;
	t_vector2d t;


	C = sphere.center;
	R = sphere.radius;
	Cam_C = vec_diff(camera, C);
	k1 = dot_product(D, D);
	k2 = 2 * dot_product(Cam_C, D);
	k3 = dot_product(Cam_C, Cam_C) - R * R;
	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
	{
		res = (t_vector2d)(inf, inf);
		return (res);
	}
	t.x = (- k2 + sqrt(discriminant)) / (2 * k1);
	t.y = (- k2 - sqrt(discriminant)) / (2 * k1);
	return (t);
}

int		trace_ray(t_camera *camera, t_vector3d *D, double t_min, double t_max)
{
	//!! double t1, t2; ??double????
	t_vector2d t; 
	closest_t = inf; //?? mb tut t_max
	closest_sphere = NULL;
	for sphere in scene.spheres
	{
		t.x = intersect_ray_sphere(camera, D, sphere);
		t.y = intersect_ray_sphere(camera, D, sphere);
		if ((t1 >= t_min && t1 <= t_max) && t1 < closest_t)
			closest_t = t1;
			closest_sphere = sphere;
		if ((t2 >= t_min && t2 <= t_max) && t2 < cllosest_t)
			closest_t = t2;
			closest_sphere = sphere;
	}
	if (closest_sphere == NULL)
		return (BACKGROUND_COLOR);
	return closest_sphere.color;
}
