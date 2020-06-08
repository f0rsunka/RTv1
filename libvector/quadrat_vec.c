
#include "include/libvector.h"

t_vec3 quadrat_vec(t_vec3 a)
{
	t_vec3 c;

	c.x = a.x * a.x;
	c.y = a.y * a.y;
	c.z = a.z * a.z;
	return (c);
}
