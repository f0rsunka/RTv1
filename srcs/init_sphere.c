
#include "rtv1.h"

void	init_sphere_0(t_sphere *sphere)
{
	// sphere->color = transform_color(PINK);
	sphere->center = (t_vec3){0.0, -1.0, 4.0};
	// sphere->center = (t_vec3){6.0, 2.0, 0.0};
	sphere->radius = 2.0f;
	// sphere->material.specular = transform_specular(800.0f);
	sphere->material.color = transform_color(PINK);
	sphere->material.specular = 50.0f;
	sphere->material.a = (t_vec2){0.6f, 0.3f};
}

void	init_sphere_1(t_sphere *sphere)
{
	// sphere->color = transform_color(BLUE);
	sphere->center = (t_vec3){-2.0, 1.0, 4.0};
	// sphere->center = (t_vec3){1.5, -0.5, -18.0};
	sphere->radius = 2.0f;
	sphere->material.color = transform_color(BLUE);
	sphere->material.specular = 50.0f;
	sphere->material.a = (t_vec2){0.6f, 0.3f};
	// sphere->material.specular = transform_specular(800.0f);
}

void	init_sphere_2(t_sphere *sphere)
{
	// sphere->color = transform_color(PURPLE);
	sphere->center = (t_vec3){2.0f, 1.0, 4.0};
	// sphere->center = (t_vec3){7.0f, 5.0, -18.0};
	sphere->radius = 2.0f;
	sphere->material.color = transform_color(PURPLE);
	sphere->material.specular = 10.0f;
	sphere->material.a = (t_vec2){0.9f, 0.1f};
	// sphere->material.specular = transform_specular(500.0f);
}

void	choice_sphere(int i, t_scene *scene)
{
	scene->object = (t_sphere*)malloc(sizeof(t_sphere));
	// sphere = (t_sphere*)malloc(sizeof(t_sphere));
	(scene->object == NULL ? exit(88) : 14);
	scene->type = SPHERE;
	if (i == 0)
		init_sphere_0((t_sphere *)scene->object);
	if (i == 1)
		init_sphere_1((t_sphere *)scene->object);
	if (i == 2)
		init_sphere_2((t_sphere *)scene->object);
	// scene->object = (t_sphere*)sphere;
}
