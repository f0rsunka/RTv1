
#include "rtv1.h"

void	calculate_diffuse(t_light light, t_vec3 normal, float *intensity)
{
	float dot_l_n;
	float len_l;
	float len_n;

	// dot_l_n = dot_product(light.direction, normal);
	dot_l_n = dot_product(light.direction, normal);
	dot_l_n *= -1;
	if (dot_l_n > 0)
	{
		// printf("%f\n", dot_l_n);
		len_l = vec_length(light.direction);
		len_n = vec_length(normal);
		*intensity = light.intensity * dot_l_n / (len_l * len_n);
		// *intensity = light.intensity * dot_l_n;
	}
}
