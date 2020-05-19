
#include "rtv1.h"

float	quadratic_equation_cylinder(t_vec3 ofs, t_vec3 dir, float *t1, float *t2)
{
	t_coefficients	c;
	float			d;

	c.a = calc_a(dir);
	c.b = calc_b(ofs, dir);
	c.c = calc_c(ofs, 1);
	d = calc_discriminant(c.a, c.b, c.c);
	if (d < 0)
		return (0);
	*t1 = (- c.b + sqrtf(d)) / (2 * c.a);
	*t2 = (- c.b - sqrtf(d)) / (2 * c.a);
	return (1);
}

