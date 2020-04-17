
#include "rtv1.h"

float	calculate_diffuse(float light_intensity, t_vec3 light_dir, t_vec3 normal_dir)
{
	float dot_l_n;
	float len_l;
	float len_n;
	float intensity;

	dot_l_n = dot_product(light_dir, normal_dir);
	if (dot_l_n <= 0)
	{
		return (0.0f);
	}
	len_l = vec_length(light_dir);
	len_n = vec_length(normal_dir);
	intensity = light_intensity * dot_l_n / (len_l * len_n);
	return (intensity);
}
