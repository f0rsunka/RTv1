
#include "rtv1.h"

float	calculate_reflection(t_vec3 view, t_vec3 light_dir, float light_intensity, t_intersect intersect)
{
	t_vec3	reflection;
	float	dot_l_n;
	float	dot_r_v;
	float	len_r;
	float	len_v;
	float	intensity;
	float	x;

	dot_l_n = dot_product(light_dir, intersect.normal);
	reflection = vec_diff(light_dir, vec_add_const(vec_add_const(intersect.normal, 2.0f), dot_l_n));
	dot_r_v = dot_product(reflection, view);
	if (dot_r_v <= 0)
		return (0.0f);
	len_r = vec_length(reflection);
	len_v = vec_length(view);
	x = (dot_r_v / (len_r * len_v));
	intensity = light_intensity * powf(x, intersect.material.specular);
	return (intensity);
}
