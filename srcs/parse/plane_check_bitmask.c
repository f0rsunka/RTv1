/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_check_bitmask.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:28:29 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 11:40:26 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		offset_check_keyed_double(short *bitmask, char *line,
														t_plane *plane)
{
	if (read_keyed_double(line, "    offset_x:", &(plane->offset.x)))
		*bitmask += 1u << 0u;
	if (read_keyed_double(line, "    offset_y:", &(plane->offset.y)))
		*bitmask += 1u << 1u;
	if (read_keyed_double(line, "    offset_z:", &(plane->offset.z)))
		*bitmask += 1u << 2u;
}

static void		normal_check_keyed_double(short *bitmask, char *line,
														t_plane *plane)
{
	if (read_keyed_double(line, "    normal_x:", &(plane->normal.x)))
		*bitmask += 1u << 3u;
	if (read_keyed_double(line, "    normal_y:", &(plane->normal.y)))
		*bitmask += 1u << 4u;
	if (read_keyed_double(line, "    normal_z:", &(plane->normal.z)))
		*bitmask += 1u << 5u;
	check_normal_plane(plane->normal);
}

static void		coef_check_keyed_double(short *bitmask, char *line,
														t_plane *plane)
{
	if (read_keyed_double(line, "    coef_x:", &(plane->coef.x)))
		*bitmask += 1u << 9u;
	if (read_keyed_double(line, "    coef_y:", &(plane->coef.y)))
		*bitmask += 1u << 10u;
	if (read_keyed_double(line, "    coef_z:", &(plane->coef.z)))
		*bitmask += 1u << 11u;
}

static void		material_check_keyed_double(short *bitmask, char *line,
														t_plane *plane)
{
	if (read_keyed_float(line, "    color_r:", &(plane->material.color.r)))
		*bitmask += 1u << 6u;
	if (read_keyed_float(line, "    color_g:", &(plane->material.color.g)))
		*bitmask += 1u << 7u;
	if (read_keyed_float(line, "    color_b:", &(plane->material.color.b)))
		*bitmask += 1u << 8u;
	if (read_keyed_float(line, "    specular:", &(plane->material.specular)))
		*bitmask += 1u << 12u;
	check_specular(plane->material.specular);
}

size_t			plane_check_bitmask(short *bitmask, t_plane *plane,
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
		offset_check_keyed_double(bitmask, *line, plane);
		normal_check_keyed_double(bitmask, *line, plane);
		coef_check_keyed_double(bitmask, *line, plane);
		material_check_keyed_double(bitmask, *line, plane);
		i++;
		ft_memdel((void**)line);
	}
}
