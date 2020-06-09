/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_quadratic_equation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:13:06 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 12:24:22 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	calc_discriminant(float a, float b, float c)
{
	float d;

	d = b * b - 4 * a * c;
	return (d);
}

void	sphere_calc_coefficients(t_coefficients *c, t_vec3 ofs, t_vec3 dir,
																	float r)
{
	c->a = dot_product(dir, dir);
	c->b = 2 * dot_product(ofs, dir);
	c->c = dot_product(ofs, ofs) - r * r;
}

void	cylinder_calc_coefficients(t_coefficients *c, t_vec3 ofs, t_vec3 dir,
															t_cylinder cylinder)
{
	c->a = cylinder.coef.x * (dir.x * dir.x) +
		cylinder.coef.y * (dir.y * dir.y) + cylinder.coef.z * (dir.z * dir.z);
	c->b = 2 * (cylinder.coef.x * (ofs.x * dir.x) +
		cylinder.coef.y * (ofs.y * dir.y) + cylinder.coef.z * (ofs.z * dir.z));
	c->c = cylinder.coef.x * (ofs.x * ofs.x) +
		cylinder.coef.y * (ofs.y * ofs.y) + cylinder.coef.z * (ofs.z * ofs.z)
															- cylinder.radius;
}

void	cone_calc_coefficients(t_coefficients *c, t_vec3 ofs, t_vec3 dir,
																	t_cone cone)
{
	c->a = (dir.x * dir.x) / cone.coef.x -
				(dir.y * dir.y) / cone.coef.y + (dir.z * dir.z) / cone.coef.z;
	c->b = 2 * ((ofs.x * dir.x) / cone.coef.x -
				(ofs.y * dir.y) / cone.coef.y + (ofs.z * dir.z) / cone.coef.z);
	c->c = (ofs.x * ofs.x) / cone.coef.x -
				(ofs.y * ofs.y) / cone.coef.y + (ofs.z * ofs.z) / cone.coef.z;
}

int		is_sqrt_valide(float t1, float t2, float *dist)
{
	if (t1 > 0 && t2 < 0)
	{
		*dist = t1;
		return (1);
	}
	if (t2 > 0 && t1 < 0)
	{
		*dist = t2;
		return (1);
	}
	if (t1 < t2 && t1 >= 0)
	{
		*dist = t1;
		return (1);
	}
	if (t2 < t1 && t2 >= 0)
	{
		*dist = t2;
		return (1);
	}
	return (0);
}
