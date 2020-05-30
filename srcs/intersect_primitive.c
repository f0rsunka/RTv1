
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
	if (t1 <= 0 && t2 >= 0)
	{
		*sphere_dist = t2;
		return (1);
	}
	if (t2 <= 0 && t1 >= 0)
	{
		*sphere_dist = t1;
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
	ofs = vec_diff(camera, cylinder.offset);
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
	if (t1 <= 0 && t2 >= 0)
	{
		*cylinder_dist = t2;
		return (1);
	}
	if (t2 <= 0 && t1 >= 0)
	{
		*cylinder_dist = t1;
		return (1);
	}
	return (0);
}

int 		intersect_ray_cone(t_vec3 camera, t_vec3 dir, t_cone *cone, float *cone_dist)
{
	t_vec3	ofs;
	float	t1;
	float	t2;

	*cone_dist = 0.0f;
	ofs = vec_diff(camera, cone->offset);
	// printf("cone->offset = %f %f %f\n", cone->offset.x, cone->offset.y, cone->offset.z);
	// ofs = division_vec(camera, cone->offset);
	// printf("%f %f %f\n", ofs.x, ofs.y, ofs.z);
	// printf("%d\n", quadratic_equation_cone(cone, camera, cone->offset, ofs, dir, &t1, &t2));
	if (!quadratic_equation_cone(*cone, camera, cone->offset, ofs, dir, &t1, &t2))
		return (0);
	// printf("\n***\nt1 = %f\nt2 = %f\n\n", t1, t2);
	if (t1 < t2 && t1 >= 0)
	{
		*cone_dist = t1;
		return (1);
	}
	if (t2 < t1 && t2 >= 0)
	{
		*cone_dist = t2;
		return (1);
	}
	if (t1 <= 0 && t2 >= 0)
	{
		*cone_dist = t2;
		return (1);
	}
	if (t2 <= 0 && t1 >= 0)
	{
		*cone_dist = t1;
		return (1);
	}
	return (1);
}

// int		intersect_plane(t_rtv *r, t_plane *plane)
// {
// 	float t;
// 	float dot_r_n;

// 	t = -1 * (camera.y / dir.y);
// 	r->ray.p = mult_vec(camera, mult_vec_const(dir, t));
// 	dot_r_n = dot_product(r->ray.p, plane->normal);
// 	if (dot_r_n > 0)
// 	*plane_dist = 0.0f;
// 	if (t >= 0)
// 	{
// 		*plane_dist = t;
// 		return (1);
// 	}
// return (0);
// }
