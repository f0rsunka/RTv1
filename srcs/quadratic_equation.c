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

int	quadratic_equation_sphere(t_vec3 length_cam_center, t_vec3 dir, float r, float *t1, float *t2)
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

int	quadratic_equation_cylinder(t_vec3 ofs, t_vec3 dir, float *t1, float *t2)
{
	t_coefficients	c;
	float			d;

	c.a = calc_a(dir);
	c.b = calc_b(ofs, dir);
	c.c = calc_c(ofs, 3);
	d = calc_discriminant(c.a, c.b, c.c);
	if (d < 0)
		return (0);
	*t1 = (- c.b + sqrtf(d)) / (2 * c.a);
	*t2 = (- c.b - sqrtf(d)) / (2 * c.a);
	return (1);
}

float	calc_div(float a, float b)
{
	float res;

	res = a / b;
	return (res);
}

// float	quadratic_equation_cone(t_cone cone, t_vec3 camera, t_vec3 center, t_vec3 ofs, t_vec3 dir, float *t1, float *t2)
// {
// 	t_coefficients	c;
// 	// t_vec3			n;
// 	// float x,y,z;
// 	float			d;

// 	// c.a = (dir.x / center.x) * (dir.x / center.x) - dir.y + (dir.z / center.z) * (dir.z / center.z);
// 	// c.b = 2 * (ofs.x * (dir.x / center.x) - camera.y * dir.y + ofs.z * (dir.z / center.z));
// 	// c.c = ofs.x * ofs.x - camera.y * camera.y + ofs.z * ofs.z;

// 	// c.a = calc_div(dir.x * dir.x, center.x * center.x) + calc_div(dir.y * dir.y, center.y * center.y) - calc_div(dir.z * dir.z, center.z * center.z);
// 	// c.b = 2 * (ofs.x * calc_div(dir.x, center.x) + ofs.y * calc_div(dir.y, center.y)) - ofs.z * calc_div(dir.z, center.z);
// 	// c.c = ofs.x * ofs.x + ofs.y * ofs.y - ofs.z * ofs.z;

// 	// c.a = calc_div(dir.x * dir.x, center.x * center.x) + calc_div(dir.y * dir.y, center.y * center.y) - calc_div(dir.z * dir.z, center.z * center.z);
// 	// c.b = 2 * (ofs.x * calc_div(dir.x, center.x) + ofs.y * calc_div(dir.y, center.y)) - ofs.z * calc_div(dir.z, center.z);
// 	// c.c = ofs.x * ofs.x + ofs.y * ofs.y - ofs.z * ofs.z;


// 	// t_vec3 vector;

// 	// vector.x = cone.c.a;
// 	// vector.y = cone.c.b;
// 	// vector.z = cone.c.c;
// 	// n = division_vec(ofs,vector);

// 	// c.a = ((dir.x * dir.x) / (cone.c.a * cone.c.a)) + ((dir.y * dir.y) / (cone.c.b * cone.c.b)) - ((dir.z * dir.x) / (cone.c.c * cone.c.c));
// 	// c.b = 2 * (((ofs.x * dir.x) / (cone.c.a * cone.c.a)) + ((ofs.y * dir.y) / (cone.c.b * cone.c.b)) - ((ofs.z * dir.z) / (cone.c.c * cone.c.c)));
// 	// c.c = n.x * n.x + n.y * n.y - n.z * n.z;

// 	c.a = ((dir.x * dir.x) / (cone.c.a * cone.c.a)) + ((dir.y * dir.y) / (cone.c.b * cone.c.b)) - ((dir.z * dir.z) / (cone.c.c * cone.c.c));
// 	c.b = ((camera.x * dir.x) / (cone.c.a * cone.c.a)) + ((camera.y * dir.y) / (cone.c.b * cone.c.b)) - ((camera.z * dir.z) / (cone.c.c * cone.c.c));
// 	c.c = ((camera.x * camera.x) / (cone.c.a * cone.c.a)) + ((camera.y * camera.y) / (cone.c.b * cone.c.b)) - ((camera.z * camera.z) / (cone.c.c * cone.c.c));

// 	// printf("c = %f\n", c.c);
// 	d = calc_discriminant(c.a, c.b, c.c);
// 	// printf("%f\n", d);
// 	if (d < 0)
// 		return (0);
// 	*t1 = (- c.b + sqrtf(d)) / (2 * c.a);
// 	*t2 = (- c.b - sqrtf(d)) / (2 * c.a);
// 	return (1);
// }

int	quadratic_equation_cone(t_cone cone, t_vec3 camera, t_vec3 center, t_vec3 ofs, t_vec3 dir, float *t1, float *t2)
{
	t_coefficients	c;
	float			d;

	dir.z *= -1;
	ofs.z *= -1;
	c.a = calc_a(dir);
	// printf("\nc.a = %f\n", c.a);
	c.b = calc_b(ofs, dir);
	// printf("\nc.b = %f\n", c.b);
	c.c = calc_c(ofs, 0);
	// printf("\nc.c = %f\n", c.c);
	d = calc_discriminant(c.a, c.b, c.c);
	// printf("%f\n", d);
	if (d < 0)
		return (0);
	*t1 = (- c.b + sqrtf(d)) / (2 * c.a);
	*t2 = (- c.b - sqrtf(d)) / (2 * c.a);
	return (1);
}
