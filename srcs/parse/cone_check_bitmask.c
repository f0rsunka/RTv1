/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_check_bitmask.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:49:20 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 01:22:36 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		offset_check_keyed_double(short *bitmask, char *line, t_cone *cone)
{
	if (read_keyed_double(line, "    offset_x:", &(cone->offset.x)))
		*bitmask += 1u << 0u;
	if (read_keyed_double(line, "    offset_y:", &(cone->offset.y)))
		*bitmask += 1u << 1u;
	if (read_keyed_double(line, "    offset_z:", &(cone->offset.z)))
		*bitmask += 1u << 2u;
}

static void		coef_check_keyed_double(short *bitmask, char *line, t_cone *cone)
{
	if (read_keyed_double(line, "    coef_x:", &(cone->coef.x)))
		*bitmask += 1u << 3u;
	if (read_keyed_double(line, "    coef_y:", &(cone->coef.y)))
		*bitmask += 1u << 4u;
	if (read_keyed_double(line, "    coef_z:", &(cone->coef.z)))
		*bitmask += 1u << 5u;
}

static void		angle_check_keyed_double(short *bitmask, char *line, t_cone *cone)
{
	if (read_keyed_double(line, "    angle_x:", &(cone->angle.x)))
		*bitmask += 1u << 6u;
	if (read_keyed_double(line, "    angle_y:", &(cone->angle.y)))
		*bitmask += 1u << 7u;
	if (read_keyed_double(line, "    angle_z:", &(cone->angle.z)))
		*bitmask += 1u << 8u;
}

static void		material_check_keyed_double(short *bitmask, char *line,
																t_cone *cone)
{
	if (read_keyed_float(line, "    color_r:", &(cone->material.color.r)))
		*bitmask += 1u << 9u;
	if (read_keyed_float(line, "    color_g:", &(cone->material.color.g)))
		*bitmask += 1u << 10u;
	if (read_keyed_float(line, "    color_b:", &(cone->material.color.b)))
		*bitmask += 1u << 11u;
	if (read_keyed_float(line, "    specular:", &(cone->material.specular)))
		*bitmask += 1u << 12u;
}

size_t			cone_check_bitmask(short *bitmask, t_cone *cone, char **line,
																	int fd)
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
		offset_check_keyed_double(bitmask, *line, cone);
		coef_check_keyed_double(bitmask, *line, cone);
		angle_check_keyed_double(bitmask, *line, cone);
		material_check_keyed_double(bitmask, *line, cone);
		i++;
		ft_memdel((void**)line);
	}
	return (i);
}
