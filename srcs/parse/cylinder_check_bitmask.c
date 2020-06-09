/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_check_bitmask.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:53:57 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 01:32:42 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		offset_check_keyed_double(short *bitmask, char *line,
														t_cylinder *cylinder)
{
	if (read_keyed_double(line, "    offset_x:", &(cylinder->offset.x)))
		*bitmask += 1u << 0u;
	if (read_keyed_double(line, "    offset_y:", &(cylinder->offset.y)))
		*bitmask += 1u << 1u;
	if (read_keyed_double(line, "    offset_z:", &(cylinder->offset.z)))
		*bitmask += 1u << 2u;
}

static void		coef_check_keyed_double(short *bitmask, char *line,
														t_cylinder *cylinder)
{
	if (read_keyed_double(line, "    coef_x:", &(cylinder->coef.x)))
		*bitmask += 1u << 3u;
	if (read_keyed_double(line, "    coef_y:", &(cylinder->coef.y)))
		*bitmask += 1u << 4u;
	if (read_keyed_double(line, "    coef_z:", &(cylinder->coef.z)))
		*bitmask += 1u << 5u;
}

static void		angle_check_keyed_double(short *bitmask, char *line,
														t_cylinder *cylinder)
{
	if (read_keyed_double(line, "    angle_x:", &(cylinder->angle.x)))
		*bitmask += 1u << 6u;
	if (read_keyed_double(line, "    angle_y:", &(cylinder->angle.y)))
		*bitmask += 1u << 7u;
	if (read_keyed_double(line, "    angle_z:", &(cylinder->angle.z)))
		*bitmask += 1u << 8u;
}

static void		material_check_keyed_double(short *bitmask, char *line,
														t_cylinder *cylinder)
{
	if (read_keyed_float(line, "    color_r:",
										&(cylinder->material.color.r)))
		*bitmask += 1u << 9u;
	if (read_keyed_float(line, "    color_g:",
										&(cylinder->material.color.g)))
		*bitmask += 1u << 10u;
	if (read_keyed_float(line, "    color_b:",
										&(cylinder->material.color.b)))
		*bitmask += 1u << 11u;
	if (read_keyed_float(line, "    specular:",
										&(cylinder->material.specular)))
		*bitmask += 1u << 12u;
	if (read_keyed_float(line, "    radius:", &(cylinder->radius)))
	{
		*bitmask += 1u << 13u;
		cylinder->radius /= 100;
	}
}

size_t			cylinder_check_bitmask(short *bitmask, t_cylinder *cylinder,
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
		offset_check_keyed_double(bitmask, *line, cylinder);
		coef_check_keyed_double(bitmask, *line, cylinder);
		angle_check_keyed_double(bitmask, *line, cylinder);
		material_check_keyed_double(bitmask, *line, cylinder);
		i++;
	}
	return (i);
}
