/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_check_bitmask.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:44:14 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 12:38:41 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		center_check_keyed_double(short *bitmask, char *line,
														t_sphere *sphere)
{
	if (read_keyed_double(line, "    center_x:", &(sphere->center.x)))
		*bitmask += 1u << 0u;
	if (read_keyed_double(line, "    center_y:", &(sphere->center.y)))
		*bitmask += 1u << 1u;
	if (read_keyed_double(line, "    center_z:", &(sphere->center.z)))
		*bitmask += 1u << 2u;
}

static void		radius_check_keyed_double(short *bitmask, char *line,
														t_sphere *sphere)
{
	if (read_keyed_float(line, "    radius:", &(sphere->radius)))
	{
		*bitmask += 1u << 3u;
		sphere->radius /= 100;
	}
}

static void		material_check_keyed_double(short *bitmask, char *line,
														t_sphere *sphere)
{
	if (read_keyed_float(line, "    color_r:", &(sphere->material.color.r)))
		*bitmask += 1u << 4u;
	if (read_keyed_float(line, "    color_g:", &(sphere->material.color.g)))
		*bitmask += 1u << 5u;
	if (read_keyed_float(line, "    color_b:", &(sphere->material.color.b)))
		*bitmask += 1u << 6u;
	if (read_keyed_float(line, "    specular:", &(sphere->material.specular)))
		*bitmask += 1u << 7u;
}

static void		angle_check_keyed_double(short *bitmask, char *line,
														t_sphere *sphere)
{
	if (read_keyed_double(line, "    angle_x:", &(sphere->angle.x)))
		*bitmask += 1u << 8u;
	if (read_keyed_double(line, "    angle_y:", &(sphere->angle.y)))
		*bitmask += 1u << 9u;
	if (read_keyed_double(line, "    angle_z:", &(sphere->angle.z)))
		*bitmask += 1u << 10u;
}

size_t			sphere_check_bitmask(short *bitmask, t_sphere *sphere,
														char **line, int fd)
{
	int		status;
	size_t	i;

	i = 0;
	while ((status = get_next_line(fd, line)) > 0)
	{
		if (!**line)
		{
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break ;
		((status == -1) ? rtv_error(READ_ERROR) : 0);
		center_check_keyed_double(bitmask, *line, sphere);
		radius_check_keyed_double(bitmask, *line, sphere);
		material_check_keyed_double(bitmask, *line, sphere);
		angle_check_keyed_double(bitmask, *line, sphere);
		i++;
		ft_memdel((void**)line);
	}
	return (i);
}
