static double	calc_t(double a, double b, double d)
{
	double	t1;
	double	t2;
	double	min_t;
	double	max_t;

	t1 = (-b + sqrt(d)) / 2 * a;
	t2 = (-b - sqrt(d)) / 2 * a;
	min_t = (t1 < t2) ? t1 : t2;
	max_t = (t1 > t2) ? t1 : t2;
	return (min_t > EPSILON) ? min_t : max_t;
}





if (d < 0)
		return (0);
	t = calc_t(args.x, args.y, d);
	if (t < EPSILON)
		return (0);