
#include "rtv1.h"

void		get_normal_sphere(t_vec3 p, t_vec3 center_sphere, t_vec3 *normal)
{
	*normal = vec_diff(center_sphere, p);
}

void		get_normal_cylinder(t_vec3 p, t_vec3 offset, t_vec3 *normal)
{
	*normal = vec_diff(offset, p);
	normal->y = 0.0f;
}

void		normal(t_closest_obj closest, t_rtv *r)
{
	if (closest.type == SPHERE)
		get_normal_sphere(r->ray.p, ((t_object *)closest.obj)->center, &r->ray.normal);
	if (closest.type == CYLINDER)
		get_normal_cylinder(r->ray.p, ((t_object *)closest.obj)->offset, &r->ray.normal);
	r->ray.normal = vec_normalize(r->ray.normal);
}
