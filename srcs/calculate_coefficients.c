
#include "rtv1.h"

float	calc_discriminant(float a, float b, float c)
{
	float d;

	// printf("b * b = %f\n", b * b);
	// printf("a = %f\n", a);
	// printf("c = %f\n", c);
	// printf("%f\n", 4 * a * c);
	d = b * b - 4 * a * c;
	return (d);
}

float	calc_b(t_vec3 ofs, t_vec3 dir)
{
	float b;

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
