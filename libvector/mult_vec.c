
#include "include/libvector.h"

t_vec3 mult_vec(t_vec3 a, t_vec3 b)
{
	t_vec3 c;

    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
 
    return c;
}
 