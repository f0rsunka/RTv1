/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_quadratic_equation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:13:06 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/05/31 17:13:19 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	quadratic_equation(t_vec3 ofs, t_vec3 dir, float r, float *t1, float *t2)
{
	t_coefficients	c;
	float			d;

	c.a = calc_a(dir);
	c.b = calc_b(ofs, dir);
	c.c = calc_c(ofs, r);
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

float	calc_a(t_vec3 dir)
{
	float a;

	a = dot_product(dir, dir);
	return (a);
}

float	calc_b(t_vec3 ofs, t_vec3 dir)
{
	float b;

	b = 2 * dot_product(ofs, dir);
	return (b);
}

float	calc_c(t_vec3 ofs, float r)
{
	float c;

	c = dot_product(ofs, ofs) - r * r;
	return (c);
}
