#include "include/libvector.h"

t_vec3	division_vec(t_vec3 v1, t_vec3 v2)
{
	t_vec3 v;

	v.x = v1.x / v2.x;
	v.y = v1.y / v2.y;
	v.z = v1.z / v2.z;
	return (v);
}