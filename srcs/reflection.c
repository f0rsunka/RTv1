
#include "rtv1.h"

void	calculate_reflection(t_ray ray, t_light light, float specular, float *intensity)
{
	t_vec3	reflection;
	float	dot_l_n;
	float	dot_r_v;
	float	len_r;
	float	len_v;
	float	x;

	dot_l_n = dot_product(light.direction, ray.normal);
	reflection = vec_diff(light.direction, mult_vec_const(mult_vec_const(ray.normal, 2.0f), dot_l_n));
	dot_r_v = dot_product(reflection, ray.reverse_dir);
	// if (dot_r_v > 0)
	// {
		// printf("dd\n");
		len_r = vec_length(reflection);
		len_v = vec_length(ray.reverse_dir);
		x = dot_r_v / (len_r * len_v);
		*intensity = light.intensity * powf(x, specular);
	// }
}
