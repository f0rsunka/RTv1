
#include "rtv1.h"

void	init_sphere_0(t_sphere *sphere)
{
	sphere->center = (t_vec3){0.0, 1.0, 6.0};
	sphere->radius = 2.0f;
	sphere->material.color = float_to_byte(PINK);
	sphere->material.specular = 50.0f;
	sphere->material.a = (t_vec2){0.6f, 0.3f};
}

void	init_sphere_1(t_sphere *sphere)
{
	sphere->center = (t_vec3){-2.0, -1.0, 4.0};
	sphere->radius = 2.0f;
	sphere->material.color = float_to_byte(BLUE);
	sphere->material.specular = 50.0f;
	sphere->material.a = (t_vec2){0.6f, 0.3f};
}

void	init_sphere_2(t_sphere *sphere)
{
	sphere->center = (t_vec3){2.0f, -1.0, 4.0};
	sphere->radius = 2.0f;
	sphere->material.color = float_to_byte(PURPLE);
	sphere->material.specular = 10.0f;
	sphere->material.a = (t_vec2){0.9f, 0.1f};
}

void	init_sphere_3(t_sphere *sphere)
{
	sphere->center = (t_vec3){0.0f, -501.0f, 0.0f};
	sphere->radius = 500.0f;
	sphere->material.color = float_to_byte(PURPLE);
	sphere->material.specular = 10.0f;
	sphere->material.a = (t_vec2){0.9f, 0.1f};
}

void	init_sphere(int i, t_scene *scene)
{
	scene->object = (t_sphere*)malloc(sizeof(t_sphere));
	(scene->object == NULL ? exit(88) : 14);
	scene->type = SPHERE;
	if (i == 0)
		init_sphere_0((t_sphere *)scene->object);
	if (i == 1)
		init_sphere_1((t_sphere *)scene->object);
	if (i == 2)
		init_sphere_2((t_sphere *)scene->object);
}
