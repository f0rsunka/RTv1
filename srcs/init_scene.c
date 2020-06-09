
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
		if (read_keyed_double(*line, "    center_x:", &(plane->offset.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    center_y:", &(plane->offset.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    center_z:", &(plane->offset.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    normal_x:", &(plane->normal.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    normal_y:", &(plane->normal.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    normal_z:", &(plane->normal.z)))
			bitmask += 1u << 5u;
		if (read_keyed_float(*line, "    color_r:", &(plane->material.color.r)))
			bitmask += 1u << 6u;
		if (read_keyed_float(*line, "    color_g:", &(plane->material.color.g)))
			bitmask += 1u << 7u;
		if (read_keyed_float(*line, "    color_b:", &(plane->material.color.b)))
			bitmask += 1u << 8u;
		i++;
	}
	if (bitmask != ((1u << 9u) - 1) || i != 9)
	{
		ft_memdel((void **)&plane);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
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
		if (read_keyed_float(*line, "    radius:", &(sphere->radius)))
			bitmask += 1u << 3u;
		if (read_keyed_float(*line, "    color_r:", &(sphere->material.color.r)))
			bitmask += 1u << 4u;
		if (read_keyed_float(*line, "    color_g:", &(sphere->material.color.g)))
			bitmask += 1u << 5u;
		if (read_keyed_float(*line, "    color_b:", &(sphere->material.color.b)))
			bitmask += 1u << 6u;
		if (read_keyed_float(*line, "    specular:", &(sphere->material.specular)))
			bitmask += 1u << 7u;
		i++;
	}
	if (bitmask != ((1u << 8u) - 1) || i != 8)
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

t_sphere	*create_cone(int fd, char **line)
{
	t_sphere	*cone;
	int		status;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	cone = (t_sphere *) malloc(sizeof(t_sphere));
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
		if (read_keyed_double(*line, "    center_x:", &(cone->center.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    center_y:", &(cone->center.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    center_z:", &(cone->center.z)))
			bitmask += 1u << 2u;
		if (read_keyed_float(*line, "    radius:", &(cone->radius)))
			bitmask += 1u << 3u;
		if (read_keyed_float(*line, "    color_r:", &(cone->material.color.r)))
			bitmask += 1u << 4u;
		if (read_keyed_float(*line, "    color_g:", &(cone->material.color.g)))
			bitmask += 1u << 5u;
		if (read_keyed_float(*line, "    color_b:", &(cone->material.color.b)))
			bitmask += 1u << 6u;
		if (read_keyed_float(*line, "    specular:", &(cone->material.specular)))
			bitmask += 1u << 7u;
		i++;
	}
	if (bitmask != ((1u << 8u) - 1) || i != 8)
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

int			create_figure(t_rtv *r, int fd, t_scene *prev, char **line)
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
//	if ((prev->next = create_scene_cylinder(fd, line)))
//		return (1);
	return (0);
}

int			create_light(t_rtv *r, int fd, t_light *prev, char **line)
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

	r->scene = (t_scene *)malloc(sizeof(t_scene));
	r->scene->type = TYPE_HEAD;
	cur = r->scene;
	while (create_figure(r, fd, cur, line))
	{
		if (cur->next)
			cur = cur->next;
	}
}

void		read_lights(t_rtv *r, int fd, char **line)
{
	t_light		*cur;

	r->light = (t_light *)malloc(sizeof(t_light));
	r->light->type = LIGHT_TYPE_HEAD;
	cur = r->light;
	while (create_light(r, fd, cur, line)) {
		if (cur->next)
			cur = cur->next;
	}
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
				return ;
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
