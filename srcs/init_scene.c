
#include "rtv1.h"

int		read_keyed_double(char *line, char *key, double *data)
{
	char	*str;
//	char	*end;

	str = ft_strstr(line, key);
	if (line == str && str != 0)
	{
		// FIXME проверять правую часть при помощи strtol?
		*data = (double)ft_atoi(line + ft_strlen(key));
//		*data = strtol(line + ft_strlen(key), &end, 10);
//		if (*end != '\0') {
//			ft_putstr_fd("Invalid data [", 2);
//			ft_putstr_fd(end, 2);
//			ft_putstr_fd("] passed to [", 2);
//			ft_putstr_fd(key, 2);
//			ft_putendl_fd("]", 2);
//			exit(1);
//		}
		return (1);
	}
	return (0);
}

int		read_keyed_float(char *line, char *key, float *data)
{
	char	*str;

	str = ft_strstr(line, key);
	if (line == str && str != 0)
	{
		*data = (float)ft_atoi(line + ft_strlen(key));
		return (1);
	}
	return (0);
}

int		read_keyed_int(char *line, char *key, int *data)
{
	char	*str;

	str = ft_strstr(line, key);
	if (line == str && str != 0)
	{
		*data = (int)ft_atoi(line + ft_strlen(key));
		return (1);
	}
	return (0);
}

// scene->object = init_plane((t_vec3){0.0f, 0.0f, -13.0f}, (t_vec3){0.0f, 0.0f, 1.0f}, (t_vec3){0.0f, 0.0f, 1.0f}, (t_color)ROSE_PINK);
// scene->object = init_plane((t_vec3){0.0f, 3.0f, 0.0f}, (t_vec3){0.0f, 1.0f, 0.0f}, (t_vec3){0.0f, -1.0f, 0.0f}, (t_color)INDEPENDENCE);
// t_plane	*init_plane(t_vec3 offset, t_vec3 coef, t_vec3 normal, t_color color)

t_plane	*create_plane(int fd, char **line)
{
	t_plane	*plane;
	int		status;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	plane = (t_plane *) malloc(sizeof(t_plane));
	ft_memdel((void**)line);
	i = 0;
	while ((status = get_next_line(fd, line)) > 0) {
		if (!**line) {
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break;
		if (status == -1)
		{
			ft_putendl_fd("Read error!", 2);
			exit(1);
		}
		if (read_keyed_double(*line, "    offset_x:", &(plane->offset.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    offset_y:", &(plane->offset.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    offset_z:", &(plane->offset.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    normal_x:", &(plane->normal.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    normal_y:", &(plane->normal.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    normal_z:", &(plane->normal.z)))
			bitmask += 1u << 5u;
		if (read_keyed_double(*line, "    coef_x:", &(plane->coef.x)))
			bitmask += 1u << 9u;
		if (read_keyed_double(*line, "    coef_y:", &(plane->coef.y)))
			bitmask += 1u << 10u;
		if (read_keyed_double(*line, "    coef_z:", &(plane->coef.z)))
			bitmask += 1u << 11u;
		if (read_keyed_float(*line, "    color_r:", &(plane->material.color.r)))
			bitmask += 1u << 6u;
		if (read_keyed_float(*line, "    color_g:", &(plane->material.color.g)))
			bitmask += 1u << 7u;
		if (read_keyed_float(*line, "    color_b:", &(plane->material.color.b)))
			bitmask += 1u << 8u;
		if (read_keyed_float(*line, "    specular:", &(plane->material.specular)))
			bitmask += 1u << 12u;
		i++;
	}
	if (bitmask != ((1u << 13u) - 1) || i != 13)
	{
		ft_memdel((void **)&plane);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
	plane->angle = (t_vec3){0.0f, 0.0f, 0.0f};
	plane->material.color = float_to_byte(plane->material.color);
	return (plane);
}

t_scene		*create_scene_plane(int fd, char **line)
{
	char	*str;
	t_scene *tmp;

	str = ft_strstr(*line, "  plane:");
	if (*line == str && str != 0)
	{
		tmp = (t_scene *)malloc(sizeof(t_scene));
		tmp->object = (void *)create_plane(fd, line);
		tmp->type = TYPE_PLANE;
		tmp->next = 0;
		return (tmp);
	}
	return (0);
}

t_sphere	*create_sphere(int fd, char **line)
{
	t_sphere	*sphere;
	int		status;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	sphere = (t_sphere *) malloc(sizeof(t_sphere));
	ft_memdel((void**)line);
	i = 0;
	while ((status = get_next_line(fd, line)) > 0) {
		if (!**line) {
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break;
		if (status == -1)
		{
			ft_putendl_fd("Read error!", 2);
			exit(1);
		}
		if (read_keyed_double(*line, "    center_x:", &(sphere->center.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    center_y:", &(sphere->center.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    center_z:", &(sphere->center.z)))
			bitmask += 1u << 2u;
		if (read_keyed_float(*line, "    radius:", &(sphere->radius))) {
			bitmask += 1u << 3u;
			sphere->radius /= 100;
		}
		if (read_keyed_float(*line, "    color_r:", &(sphere->material.color.r)))
			bitmask += 1u << 4u;
		if (read_keyed_float(*line, "    color_g:", &(sphere->material.color.g)))
			bitmask += 1u << 5u;
		if (read_keyed_float(*line, "    color_b:", &(sphere->material.color.b)))
			bitmask += 1u << 6u;
		if (read_keyed_float(*line, "    specular:", &(sphere->material.specular)))
			bitmask += 1u << 7u;
		if (read_keyed_double(*line, "    angle_x:", &(sphere->angle.x)))
			bitmask += 1u << 8u;
		if (read_keyed_double(*line, "    angle_y:", &(sphere->angle.y)))
			bitmask += 1u << 9u;
		if (read_keyed_double(*line, "    angle_z:", &(sphere->angle.z)))
			bitmask += 1u << 10u;
		i++;
	}
	if (bitmask != ((1u << 11u) - 1) || i != 11)
	{
		ft_memdel((void **)&sphere);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
	sphere->material.color = float_to_byte(sphere->material.color);
	return (sphere);
}

t_scene		*create_scene_sphere(int fd, char **line)
{
	char	*str;
	t_scene *tmp;

	str = ft_strstr(*line, "  sphere:");
	if (*line == str && str != 0)
	{
		tmp = (t_scene *)malloc(sizeof(t_scene));
		tmp->object = (void *)create_sphere(fd, line);
		tmp->type = TYPE_SPHERE;
		tmp->next = 0;

		return (tmp);
	}
	return (0);
}

t_cone		*create_cone(int fd, char **line)
{
	t_cone	*cone;
	int		status;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	cone = (t_cone *)malloc(sizeof(t_cone));
	ft_memdel((void**)line);
	i = 0;
	while ((status = get_next_line(fd, line)) > 0) {
		if (!**line) {
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break;
		if (status == -1)
		{
			ft_putendl_fd("Read error!", 2);
			exit(1);
		}
		if (read_keyed_double(*line, "    offset_x:", &(cone->offset.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    offset_y:", &(cone->offset.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    offset_z:", &(cone->offset.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    coef_x:", &(cone->coef.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    coef_y:", &(cone->coef.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    coef_z:", &(cone->coef.z)))
			bitmask += 1u << 5u;
		if (read_keyed_double(*line, "    angle_x:", &(cone->angle.x)))
			bitmask += 1u << 6u;
		if (read_keyed_double(*line, "    angle_y:", &(cone->angle.y)))
			bitmask += 1u << 7u;
		if (read_keyed_double(*line, "    angle_z:", &(cone->angle.z)))
			bitmask += 1u << 8u;
		if (read_keyed_float(*line, "    color_r:", &(cone->material.color.r)))
			bitmask += 1u << 9u;
		if (read_keyed_float(*line, "    color_g:", &(cone->material.color.g)))
			bitmask += 1u << 10u;
		if (read_keyed_float(*line, "    color_b:", &(cone->material.color.b)))
			bitmask += 1u << 11u;
		if (read_keyed_float(*line, "    specular:", &(cone->material.specular)))
			bitmask += 1u << 12u;
		i++;
	}
	if (bitmask != ((1u << 13u) - 1) || i != 13)
	{
		ft_memdel((void **)&cone);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
	cone->material.color = float_to_byte(cone->material.color);
	return (cone);
}

t_scene		*create_scene_cone(int fd, char **line)
{
	char	*str;
	t_scene *tmp;

	str = ft_strstr(*line, "  cone:");
	if (*line == str && str != 0)
	{
		tmp = (t_scene *)malloc(sizeof(t_scene));
		tmp->object = (void *)create_cone(fd, line);
		tmp->type = TYPE_CONE;
		tmp->next = 0;

		return (tmp);
	}
	return (0);
}

t_cylinder	*create_cylinder(int fd, char **line)
{
	t_cylinder	*cylinder;
	int			status;
	short		bitmask;
	size_t		i;

	bitmask = 0;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	ft_memdel((void**)line);
	i = 0;
	while ((status = get_next_line(fd, line)) > 0) {
		if (!**line) {
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break;
		if (status == -1)
		{
			ft_putendl_fd("Read error!", 2);
			exit(1);
		}
		if (read_keyed_double(*line, "    offset_x:", &(cylinder->offset.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    offset_y:", &(cylinder->offset.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    offset_z:", &(cylinder->offset.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    coef_x:", &(cylinder->coef.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    coef_y:", &(cylinder->coef.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    coef_z:", &(cylinder->coef.z)))
			bitmask += 1u << 5u;
		if (read_keyed_double(*line, "    angle_x:", &(cylinder->angle.x)))
			bitmask += 1u << 6u;
		if (read_keyed_double(*line, "    angle_y:", &(cylinder->angle.y)))
			bitmask += 1u << 7u;
		if (read_keyed_double(*line, "    angle_z:", &(cylinder->angle.z)))
			bitmask += 1u << 8u;
		if (read_keyed_float(*line, "    color_r:", &(cylinder->material.color.r)))
			bitmask += 1u << 9u;
		if (read_keyed_float(*line, "    color_g:", &(cylinder->material.color.g)))
			bitmask += 1u << 10u;
		if (read_keyed_float(*line, "    color_b:", &(cylinder->material.color.b)))
			bitmask += 1u << 11u;
		if (read_keyed_float(*line, "    specular:", &(cylinder->material.specular)))
			bitmask += 1u << 12u;
		if (read_keyed_float(*line, "    radius:", &(cylinder->radius))) {
			bitmask += 1u << 13u;
			cylinder->radius /= 100;
		}
		i++;
	}
	if (bitmask != ((1u << 14u) - 1) || i != 14)
	{
		ft_memdel((void **)&cylinder);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
	cylinder->material.color = float_to_byte(cylinder->material.color);
	return (cylinder);
}

t_scene		*create_scene_cylinder(int fd, char **line)
{
	char	*str;
	t_scene *tmp;

	str = ft_strstr(*line, "  cylinder:");
	if (*line == str && str != 0)
	{
		tmp = (t_scene *)malloc(sizeof(t_scene));
		tmp->object = (void *)create_cylinder(fd, line);
		tmp->type = TYPE_CYLINDER;
		tmp->next = 0;

		return (tmp);
	}
	return (0);
}

void		parse_light(int fd, char **line, t_light *light)
{
	int		status;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	ft_memdel((void**)line);
	i = 0;
	while ((status = get_next_line(fd, line))) {
		if (!**line) {
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break;
		if (status == -1)
		{
			ft_putendl_fd("Read error!", 2);
			exit(1);
		}
		if (read_keyed_double(*line, "    position_x:", &(light->position.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    position_y:", &(light->position.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    position_z:", &(light->position.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    direction_x:", &(light->direction.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    direction_y:", &(light->direction.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    direction_z:", &(light->direction.z)))
			bitmask += 1u << 5u;
		if (read_keyed_float(*line, "    intensity:", &(light->intensity))) {
			bitmask += 1u << 6u;
			light->intensity /= 100;
		}
		if (read_keyed_int(*line, "    type:", &(light->type)))
			bitmask += 1u << 7u;
		i++;
	}
	if (bitmask != ((1u << 8u) - 1) || i != 8)
	{
		ft_memdel((void **)&light);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
}

t_light 	*create_light_light(int fd, char **line)
{
	char	*str;
	t_light *tmp;

	str = ft_strstr(*line, "  light:");
	if (*line == str && str != 0)
	{
		tmp = (t_light *)malloc(sizeof(t_light));
		parse_light(fd, line, tmp);
		tmp->next = 0;
		return (tmp);
	}
	return (0);
}

int			create_figure(int fd, t_scene *prev, char **line)
{
	int		status;

	if (*line == 0)
	{
		status = get_next_line(fd, line);
		if (status == -1)
		{
			ft_putendl_fd("Read error!", 2);
			exit(1);
		}
		if (status == 0)
		{
			// TODO проверить молочит ли гнл лайн при статусе 0, если да, то тут зафришить лайн
			return (0);
		}
	}
	if (**line == '\0')
	{
		ft_memdel((void**)line);
		return (1);
	}
	if ((prev->next = create_scene_plane(fd, line)))
		return (1);
	if ((prev->next = create_scene_sphere(fd, line)))
		return (1);
	if ((prev->next = create_scene_cone(fd, line)))
		return (1);
	if ((prev->next = create_scene_cylinder(fd, line)))
		return (1);
	return (0);
}

int			create_light(int fd, t_light *prev, char **line)
{
	int		status;

	if (*line == 0)
	{
		status = get_next_line(fd, line);
		if (status == -1)
		{
			ft_putendl_fd("Read error!", 2);
			exit(1);
		}
		if (status == 0)
		{
			// TODO проверить молочит ли гнл лайн при статусе 0, если да, то тут зафришить лайн
			return (0);
		}
	}
	if (**line == '\0')
	{
		ft_memdel((void**)line);
		return (1);
	}
	if ((prev->next = create_light_light(fd, line)))
		return (1);
	return (0);
}

void		read_objects(t_rtv *r, int fd, char **line)
{
	t_scene		*cur;
	size_t		count;

	r->scene = (t_scene *)malloc(sizeof(t_scene));
	r->scene->type = TYPE_HEAD;
	cur = r->scene;
	count = 0;
	while (create_figure(fd, cur, line))
	{
		if (cur->next) {
			cur = cur->next;
			count++;
		}

	}
	(count <= 0 ? rtv_error(PRIMITIVES_MIN) : 0);
	(count > 7 ? rtv_error(PRIMITIVES_MAX) : 0);
}

void		read_lights(t_rtv *r, int fd, char **line)
{
	t_light		*cur;
	size_t		count;

	r->light = (t_light *)malloc(sizeof(t_light));
	r->light->type = LIGHT_TYPE_HEAD;
	cur = r->light;
	count = 0;
	while (create_light(fd, cur, line)) {
		if (cur->next) {
			cur = cur->next;
			count++;
		}
	}
	(count <= 0 ? rtv_error(LIGHT_MIN) : 0);
	(count > 3 ? rtv_error(LIGHT_MAX) : 0);
}

void        read_scene(t_rtv *r, char *filename)
{
	int			fd;
	char		*line;
	int 		status;

	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Invalid file! Expected *.rtv1 text scene file.", 2);
		exit(1);
	}
	while (1)
	{
		if (!line)
		{
			status = get_next_line(fd, &line);
			if (status < 0)
			{
				ft_putendl_fd("gnl -1", 2);
				exit(1);
			}
			if (status == 0)
			{
				// TODO проверить молочит ли гнл лайн при статусе 0, если да, то тут зафришить лайн
				break ;
			}
		}
		if (!*line)
		{
			ft_memdel((void**)&line);
			continue;
		}
		if (ft_strequ(line, "objects:"))
		{
			ft_memdel((void**)&line);
			read_objects(r, fd, &line);
			continue;
		}
		if (ft_strequ(line, "lights:"))
		{
			ft_memdel((void**)&line);
			read_lights(r, fd, &line);
			continue;
		}
		ft_putendl_fd("level 0 invalid key", 2);
		ft_putendl_fd(line, 2);
		exit(1);
	}
	close(fd);
}
