/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:29:49 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/05 22:06:01 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec2 intersect_ray_sphere(t_vec3 camera, t_vec3 point_3d, t_sphere *sphere)
{
	t_vec3 C;
	double R;
	t_vec3 OC;
	double k1;
	double k2;
	double k3;
	double discriminant;
	t_vec2 t;

	// printf("C.x = %f C.y = %f C.z = %f\n", C.x, C.y, C.z);
	C = sphere->center;
	R = sphere->radius;
	// OC = vec_diff(camera, C);
	OC = vec_diff(C, camera);

	k1 = dot_product(point_3d, point_3d);
	k2 = 2 * dot_product(OC, point_3d);
	// k3 = dot_product(OC, OC) - R * R;
	k3 = dot_product(C, C) + dot_product(point_3d, point_3d) - 2 * dot_product(point_3d, C) - R * R;
	discriminant = k2 * k2 - 4 * k1 * k3;
	// printf("discr = %f\n", discriminant);
	if (discriminant < 0)
		return ((t_vec2){FLT_MAX, FLT_MAX});
	t.x = (- k2 + sqrt(discriminant)) / (2 * k1);
	t.y = (- k2 - sqrt(discriminant)) / (2 * k1);
	return (t);
}

/*
** trace_ray - вычисляет пересечение луча с каждой сферой, и возвращает цвет сферы
** в ближайшей точке пересечения, которая находится в требуемом интервале t
*/ 

t_color		trace_ray(t_vec3 camera, t_vec3 point_3d, double t_min, t_rtv *r)
{
	//?? double t1, t2;
	t_sphere	*closest_sphere;
	t_vec2	t;
	double		closest_t;
	t_color		c;
	int			i = 0;

	closest_t = T_MAX;
	closest_sphere = NULL;
	while (i < r->count_objects)
	{
		t = intersect_ray_sphere(camera, point_3d, r->sphere[i]);
		if (t.x != FLT_MAX && t.y != FLT_MAX)
		{
			if ((t.x >= t_min && t.x <= T_MAX) && t.x < closest_t)
			{
				// printf("condition one is perfect!\n");
				// closest_sphere = (t_sphere*)malloc(sizeof(t_sphere));
				// (closest_sphere == NULL ? exit(33) : 1);
				closest_t = t.x;
				closest_sphere = r->sphere[i];
				// printf("closest_sphere: c = %f %f %f\n", closest_sphere->center.x, closest_sphere->center.y, closest_sphere->center.z);
			}
			else if ((t.y >= t_min && t.y <= T_MAX) && t.y < closest_t)
			{
				// printf("condition two is perfect!\n");
				closest_t = t.y;
				closest_sphere = r->sphere[i];
			}
		}
		i++;
	}
	if (closest_sphere == NULL)
	{
		c = (t_color){131, 120, 158};
		return (c);
	}
	return (closest_sphere->color);
}
