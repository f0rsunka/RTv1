
#include "rtv1.h"

int		read_keyed_double(char *line, char *key, double *data)
{
	char	*str;

	str = ft_strstr(line, key);
	if (line == str && str != 0)
	{
		// FIXME проверять правую часть при помощи strtol?
		*data = (double)ft_atoi(line + ft_strlen(key));
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

t_plane	*create_plane(int fd, char **line)
{
	t_plane	*plane;
	int		status;
	short	bitmask;

	bitmask = 0;
	plane = (t_plane *) malloc(sizeof(t_plane));
	ft_memdel((void**)line);
	while ((status = get_next_line(fd, line))) {
		if (**line != ' ')
			break;
		if (status == -1)
		{
			ft_putendl_fd("Read error!", 2);
			exit(1);
		}
		if (read_keyed_double(*line, "  center_x:", &(plane->center.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "  center_y:", &(plane->center.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "  center_z:", &(plane->center.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "  normal_x:", &(plane->normal.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "  normal_y:", &(plane->normal.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "  normal_z:", &(plane->normal.z)))
			bitmask += 1u << 5u;
		if (read_keyed_float(*line, "  color_r:", &(plane->material.color.r)))
			bitmask += 1u << 6u;
		if (read_keyed_float(*line, "  color_g:", &(plane->material.color.g)))
			bitmask += 1u << 7u;
		if (read_keyed_float(*line, "  color_b:", &(plane->material.color.b)))
			bitmask += 1u << 8u;
	}
	if (bitmask != ((1u << 9u) - 1))
	{
		ft_memdel((void **)&plane);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
	return (plane);
}

t_scene		*create_scene_plane(int fd, char **line)
{
	char	*str;
	t_scene *tmp;

	str = ft_strstr(*line, "plane:");
	if (*line == str && str != 0)
	{
		tmp = (t_scene *)malloc(sizeof(t_scene));
		tmp->object = (void *)create_plane(fd, line);
		tmp->type = TYPE_PLANE;
		return (tmp);
	}
	return (0);
}

//t_scene		*create_scene_sphere(int fd, char **line)
//{
//	char	*str;
//	t_scene *tmp;
//
//	str = ft_strstr(line, "sphere:");
//	if (line == str && str != 0)
//	{
//		tmp = (t_scene *)malloc(sizeof(t_scene));
//		tmp->object = (void *)create_sphere(fd, &line);
//		tmp->type = TYPE_SPHERE;
//
//		return (tmp);
//	}
//	return (0);
//}

t_scene		*create_figure(int fd, t_scene *prev, char **line)
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
	if ((prev->next = create_scene_plane(fd, line)))
		return (prev->next);
//	if ((prev->next = create_scene_sphere(fd, line)))
//		return (prev->next);
	return (0);
}

void        init_scene(char *filename, t_rtv *r)
{
	int			fd;
	t_scene	*cur;
	char *line;

	r->scene = (t_scene *)malloc(sizeof(t_scene));
	r->scene->type = TYPE_HEAD;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Invalid file! Expected *.rtv1 text scene file.\n", 47);
		exit(1);
	}
	cur = r->scene;
	line = 0;
	while (create_figure(fd, cur, &line)) {
		cur = cur->next;
	}
	cur->next = 0;
    close(fd);
}
