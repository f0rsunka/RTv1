
#include "rtv1.h"

int 		intersect_ray_sphere(t_vec3 camera, t_vec3 dir, t_sphere sphere, float *sphere_dist)
{
	t_vec3	length_cam_center;
	float	t1;
	float	t2;

	*sphere_dist = 0.0f;
	length_cam_center = vec_diff(camera, sphere.center);
	if (!quadratic_equation_sphere(length_cam_center, dir, sphere.radius, &t1, &t2))
		return (0);
	if (t1 < t2 && t1 >= 0)
	{
		*sphere_dist = t1;
		return (1);
	}
	if (t2 < t1 && t2 >= 0)
	{
		*sphere_dist = t2;
		return (1);
	}
	return (0);
}

int 		intersect_ray_cylinder(t_vec3 camera, t_vec3 dir, t_cylinder cylinder, float *cylinder_dist)
{
	t_vec3	ofs;
	float	t1;
	float	t2;

	*cylinder_dist = 0.0f;
	// camera = mult_vec_const(camera, -1);
	ofs = vec_diff(cylinder.offset, camera);
	dir.y = 0.0f;
	ofs.y = 0.0f;
	if (!quadratic_equation_cylinder(ofs, dir, &t1, &t2))
		return (0);
	if (t1 < t2 && t1 >= 0)
	{
		*cylinder_dist = t1;
		return (1);
	}
	if (t2 < t1 && t2 >= 0)
	{
		*cylinder_dist = t2;
		return (1);
	}
	return (0);
}

// int		intersect_ray_plane(t_vec3 camera, t_vec3 dir, t_plane plane, float *plane_dist)
// {
// 	float t;
// 	float dot_r_n;
// 	t_vec3 p;

// 	t = -1 * (camera.y / dir.y);
// 	p = mult_vec(camera, mult_vec_const(dir, t));
// 	dot_r_n = dot_product(p, plane.normal);
// 	if (dot_r_n > 0)
// 	*plane_dist = 0.0f;
// 	if (t >= 0)
// 	{
// 		*plane_dist = t;
// 		return (1);
// 	}
// 	return (0);
// }

int		intersect_ray_plane(t_vec3 camera, t_vec3 dir, t_plane plane, float *plane_dist)
{
	float t;
	t_vec3 ofs;

	ofs = vec_diff(plane.offset, camera);
	t = ofs.x / dir.x + ofs.y / dir.y + ofs.z / dir.z;
	t *= -1;
	if (t >= 0) 
	{
		*plane_dist = t;
		return (1); // you might want to allow an epsilon here too
	}
	return (0);
}

// int 		intersect_ray_plane(t_vec3 camera, t_vec3 dir, t_plane plane, float *plane_dist)
// {
// 	float denom;
	
// 	denom = dot_product(plane.normal, dir);
// 	if (fabsf(denom) > 0.0001f) // your favorite epsilon
// 	{
// 		float t = dot_product(vec_diff(plane.center, camera), plane.normal) / denom;
// 		if (t > 10)
// 		    return 0;
// 		if (t >= 0) 
// 		{
// 			*plane_dist = t;
// 			return 1; // you might want to allow an epsilon here too
// 		}
// 	}
// 	return 0;
// }