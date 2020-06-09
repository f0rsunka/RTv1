/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:48:54 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 23:37:58 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	check_read_file(int ac, char **scene)
{
	int fd;

	(((WIN_W <= 0) || (WIN_H <= 0)) ? rtv_error(WINDOW_MIN) : 0);
	(((WIN_W > 1100) || (WIN_H > 1000)) ? rtv_error(WINDOW_MAX) : 0);
	if (ac < 2)
		rtv_error(MISS_ARG);
	if (ac > 2)
		rtv_error(TOO_MUCH_ARG);
	if ((fd = open(scene[1], O_DIRECTORY)) > 0)
		rtv_error(DIRECTORY_ERR);
	close(fd);
}

void		read_objects(t_rtv *r, int fd, char **line)
{
	t_scene		*cur;
	size_t		count;

	r->scene = (t_scene *)malloc(sizeof(t_scene));
	(r->scene == NULL ? rtv_error(MALLOC_ERROR) : 0);
	r->scene->type = TYPE_HEAD;
	cur = r->scene;
	count = 0;
	while (create_figure(fd, cur, line))
	{
		if (cur->next)
		{
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
	(r->light == NULL ? rtv_error(MALLOC_ERROR) : 0);
	r->light->type = LIGHT_TYPE_HEAD;
	cur = r->light;
	count = 0;
	while (create_light(fd, cur, line))
	{
		if (cur->next)
		{
			cur = cur->next;
			count++;
		}
	}
	(count <= 0 ? rtv_error(LIGHT_MIN) : 0);
	(count > 3 ? rtv_error(LIGHT_MAX) : 0);
}

int 		check_read(char **line, t_rtv *r, unsigned char is_read[2], int fd)
{
	if (!**line)
	{
		ft_memdel((void**)line);
		return (1);
	}
	if (ft_strequ(*line, "objects:"))
	{
		((is_read[0]) ? rtv_error(OBJ_ERROR) : 0);
		ft_memdel((void**)line);
		read_objects(r, fd, line);
		is_read[0] = 1;
		return (1);
	}
	if (ft_strequ(*line, "lights:"))
	{
		((is_read[1]) ? rtv_error(LIGHTS_ERROR) : 0);
		ft_memdel((void**)line);
		read_lights(r, fd, line);
		is_read[1] = 1;
		return (1);
	}
	return (0);
}

void        read_scene(t_rtv *r, char *filename)
{
	int				fd;
	char			*line;
	int 			status;
	unsigned char	is_read[2];

	line = 0;
	ft_bzero(is_read, 2);
	if ((fd = open(filename, O_RDONLY)) < 3)
		rtv_error(NOT_A_FILE);
	while (1)
	{
		if (!line)
		{
			status = get_next_line(fd, &line);
			(status < 0 ? rtv_error(GNL_ERROR) : 0);
			if (status == 0)
				break;
		}
		if (check_read(&line, r, is_read, fd))
			continue;
		ft_putendl_fd("level 0 invalid key\n", 2);
		ft_putendl_fd(line, 2);
		exit(1);
	}
	close(fd);
}
