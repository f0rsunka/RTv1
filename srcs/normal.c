
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

void		get_normal_cone(t_vec3 p, t_vec3 offset, t_vec3 *normal)
{
	*normal = vec_diff(offset, p);
}

// void		get_normal_plane(t_plane *plane, t_vec3 *normal)
// {
// 	*normal = (t_vec3){plane->coef.x, plane->coef.y, plane->coef.z};
// }

void		normal(t_closest_obj closest, t_rtv *r)
{
	if (closest.type == SPHERE)
		get_normal_sphere(r->ray.p, ((t_sphere *)closest.obj)->center, &r->ray.normal);
	if (closest.type == CYLINDER)
		get_normal_cylinder(r->ray.p, ((t_cylinder *)closest.obj)->offset, &r->ray.normal);
	if (closest.type == CONE)
		get_normal_cone(r->ray.p, ((t_cone *)closest.obj)->offset, &r->ray.normal);
	// if (closest.type == PLANE_1 || closest.type == PLANE_2 || closest.type == PLANE_3)
	// 	get_normal_plane((t_plane *)closest.obj, &r->ray.normal);
	r->ray.normal = vec_normalize(r->ray.normal);
}
