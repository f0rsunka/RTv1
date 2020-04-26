
#include "rtv1.h"

float	calculate_diffuse(float light_intensity, t_vec3 light_dir, t_vec3 normal)
{
	float dot_l_n;
	float len_l;
	float len_n;
	float intensity;

	dot_l_n = dot_product(light_dir, normal);
	if (dot_l_n <= 0)
	{
		return (0.0f);
	}
	// len_l = vec_length(light_dir);
	// len_n = vec_length(normal);
	// intensity = light_intensity * dot_l_n / (len_l * len_n);
	intensity = light_intensity * dot_l_n;
	return (intensity);
}
