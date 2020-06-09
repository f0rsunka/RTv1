/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:56:21 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 20:27:46 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			create_figure(int fd, t_scene *prev, char **line)
{
	int		status;

	if (*line == 0)
	{
		status = get_next_line(fd, line);
		((status == -1) ? rtv_error(READ_ERROR) : 0);
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
		((status == -1) ? rtv_error(READ_ERROR) : 0);
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
	if ((prev->next = create_scene_light(fd, line)))
		return (1);
	return (0);
}
