/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_primitives.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:39:57 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 00:11:40 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

t_scene		*create_scene_sphere(int fd, char **line)
{
	char	*str;
	t_scene *tmp;

	str = ft_strstr(*line, "  sphere:");
	if (*line == str && str != 0)
	{
		tmp = (t_scene *)malloc(sizeof(t_scene));
		(tmp == NULL ? rtv_error(MALLOC_ERROR) : 0);
		tmp->object = (void *)create_sphere(fd, line);
		tmp->type = TYPE_SPHERE;
		tmp->next = 0;
		return (tmp);
	}
	return (0);
}

t_scene		*create_scene_cylinder(int fd, char **line)
{
	char	*str;
	t_scene *tmp;

	str = ft_strstr(*line, "  cylinder:");
	if (*line == str && str != 0)
	{
		tmp = (t_scene *)malloc(sizeof(t_scene));
		(tmp == NULL ? rtv_error(MALLOC_ERROR) : 0);
		tmp->object = (void *)create_cylinder(fd, line);
		tmp->type = TYPE_CYLINDER;
		tmp->next = 0;
		return (tmp);
	}
	return (0);
}

t_scene		*create_scene_cone(int fd, char **line)
{
	char	*str;
	t_scene *tmp;

	str = ft_strstr(*line, "  cone:");
	if (*line == str && str != 0)
	{
		tmp = (t_scene *)malloc(sizeof(t_scene));
		(tmp == NULL ? rtv_error(MALLOC_ERROR) : 0);
		tmp->object = (void *)create_cone(fd, line);
		tmp->type = TYPE_CONE;
		tmp->next = 0;
		return (tmp);
	}
	return (0);
}
