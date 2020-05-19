/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_equation.c 	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:53:06 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/14 15:54:22 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	quadratic_equation_sphere(t_vec3 length_cam_center, t_vec3 dir, float r, float *t1, float *t2)
{
	t_coefficients	c;
	float			d;

	c.a = calc_a(dir);
	c.b = calc_b(length_cam_center, dir);
	c.c = calc_c(length_cam_center, r);
	d = calc_discriminant(c.a, c.b, c.c);
	if (d < 0)
		return (0);
	*t1 = (- c.b + sqrtf(d)) / (2 * c.a);
	*t2 = (- c.b - sqrtf(d)) / (2 * c.a);
	return (1);
}

float	calc_discriminant(float a, float b, float c)
{
	float d;

	d = b * b - 4 * a * c;
	return (d);
}

float	calc_b(t_vec3 length_cam_center, t_vec3 dir)
{
	float b;

	b = 2 * dot_product(length_cam_center, dir);
	return (b);
}

float	calc_a(t_vec3 dir)
{
	float a;

	a = dot_product(dir, dir);
	return (a);
}

float	calc_c(t_vec3 length_cam_center, float r)
{
	float c;

	c = dot_product(length_cam_center, length_cam_center) - r * r;
	return (c);
}
