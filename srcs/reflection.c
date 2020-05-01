
#include "rtv1.h"

void	calculate_reflection(t_ray ray, t_light light, float specular, float *intensity)
{
	t_vec3	reflection;
	float	dot_l_n;
	float	dot_r_v;
	float	len_r;
	float	len_v;
	float	x;

	// light.direction = mult_vec_const(light.direction, -1);
	dot_l_n = dot_product(light.direction, ray.normal);
	// reflection = vec_diff(light.direction, mult_vec_const(mult_vec_const(ray.normal, 2.0f), dot_l_n)); //right
	reflection = vec_diff(light.direction, mult_vec_const(ray.normal, dot_l_n * 2.0f));
	dot_r_v = dot_product(reflection, ray.dir);
	if (dot_r_v > 0)
	{
		// printf("dd\n");
		len_r = vec_length(reflection);
		len_v = vec_length(ray.dir);
		x = dot_r_v / (len_r * len_v);
		*intensity += light.intensity * powf(x, specular);
	}
	else
		*intensity += 0.01;
}
