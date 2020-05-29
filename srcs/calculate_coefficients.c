
#include "rtv1.h"

float	calc_discriminant(float a, float b, float c)
{
	float d;

	d = b * b - 4 * a * c;
	return (d);
}

float	calc_b(t_vec3 ofs, t_vec3 dir)
{
	float b;

	dir.z *= -1;
	b = 2 * dot_product(ofs, dir);
	return (b);
}

float	calc_a(t_vec3 dir)
{
	float a;

	a = dot_product(dir, dir);
	return (a);
}

float	calc_c(t_vec3 ofs, float r)
{
	float c;

	c = dot_product(ofs, ofs) - r * r;
	return (c);
}
