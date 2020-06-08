
	((t_cone *)scene->object)->offset = (t_vec3){0.0f, 0.0f, 0.0f};
	((t_cone *)scene->object)->c = (t_coefficients){3.0f, 1.0f, -1.0f};

float	quadratic_equation_cone(t_cone cone, t_vec3 camera, t_vec3 center, t_vec3 ofs, t_vec3 dir, float *t1, float *t2)
{
	t_coefficients	c;
	t_vec3			n;
	// float x,y,z;
	float			d;
	t_vec3 vector;

	vector.x = cone.c.a;
	vector.y = cone.c.b;
	vector.z = cone.c.c;
	n = division_vec(ofs,vector);

	c.a = ((dir.x * dir.x) / (cone.c.a * cone.c.a)) + ((dir.y * dir.y) / (cone.c.b * cone.c.b)) - ((dir.z * dir.x) / (cone.c.c * cone.c.c));
	c.b = 2 * (((ofs.x * dir.x) / (cone.c.a * cone.c.a)) + ((ofs.y * dir.y) / (cone.c.b * cone.c.b)) - ((ofs.z * dir.z) / (cone.c.c * cone.c.c)));
	c.c = n.x * n.x + n.y * n.y - n.z * n.z;
	// printf("c = %f\n", c.c);
	d = calc_discriminant(c.a, c.b, c.c);
	// printf("%f\n", d);
	if (d < 0)
		return (0);
	*t1 = (- c.b + sqrtf(d)) / (2 * c.a);
	*t2 = (- c.b - sqrtf(d)) / (2 * c.a);
	return (1);