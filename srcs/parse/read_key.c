/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 20:01:21 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 20:01:50 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//		if (*end != '\0')
		// {
//			ft_putstr_fd("Invalid data [", 2);
//			ft_putstr_fd(end, 2);
//			ft_putstr_fd("] passed to [", 2);
//			ft_putstr_fd(key, 2);
//			ft_putendl_fd("]", 2);
//			exit(1);
		// }
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
