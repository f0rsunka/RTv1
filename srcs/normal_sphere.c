
#include "rtv1.h"

t_vec3		get_normal_sphere(t_vec3 p, t_vec3 center_sphere)
{
	t_vec3	normal;
	t_vec3	normal_dir;
	
	normal = vec_diff(center_sphere, p);
	normal_dir = vec_normalize(normal);
	return (normal_dir);
}
