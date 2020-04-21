
#include "rtv1.h"

void	init_sphere_0(t_sphere *sphere)
{
	sphere->material.color = transform_color(PINK);
	// sphere->center = (t_vec3){0.0, 0.0, 3.0};
	sphere->center = (t_vec3){0.0, -1.0, 3.0};
	sphere->radius = 1.0f;
	sphere->material.specular = transform_specular(800.0f);
	// sphere->material.specular = 500.0f;
}

void	init_sphere_1(t_sphere *sphere)
{
	sphere->material.color = transform_color(BLUE);
	// sphere->center = (t_vec3){1.2, 0.0, 3.0};
	sphere->center = (t_vec3){-2.0, 1.0, 3.0};
	sphere->radius = 1.0f;
	// sphere->material.specular = 500.0f;
	sphere->material.specular = transform_specular(800.0f);
}

void	init_sphere_2(t_sphere *sphere)
{
	sphere->material.color = transform_color(PURPLE);
	// sphere->center = (t_vec3){-1.2f, 0.0, 3.0};
	sphere->center = (t_vec3){2.0f, 1.0, 3.0};
	sphere->radius = 1.0f;
	// sphere->material.specular = 500.0f;
	sphere->material.specular = transform_specular(800.0f);
}

void	choice_sphere(int i, t_sphere *sphere)
{
	sphere = (t_sphere*)(sizeof(t_sphere));
	(sphere == NULL ? exit(88) : 14);
	if (i == 0)
		init_sphere_0(sphere);
	if (i == 1)
		init_sphere_1(sphere);
	if (i == 2)
		init_sphere_2(sphere);
}
