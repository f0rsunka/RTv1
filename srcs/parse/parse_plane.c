/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:43:12 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 19:43:26 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
		((status == -1) ? rtv_error(READ_ERROR) : 0);
		if (read_keyed_double(*line, "    offset_x:", &(plane->offset.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    offset_y:", &(plane->offset.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    offset_z:", &(plane->offset.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    normal_x:", &(plane->normal.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    normal_y:", &(plane->normal.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    normal_z:", &(plane->normal.z)))
			bitmask += 1u << 5u;
		if (read_keyed_double(*line, "    coef_x:", &(plane->coef.x)))
			bitmask += 1u << 9u;
		if (read_keyed_double(*line, "    coef_y:", &(plane->coef.y)))
			bitmask += 1u << 10u;
		if (read_keyed_double(*line, "    coef_z:", &(plane->coef.z)))
			bitmask += 1u << 11u;
		if (read_keyed_float(*line, "    color_r:", &(plane->material.color.r)))
			bitmask += 1u << 6u;
		if (read_keyed_float(*line, "    color_g:", &(plane->material.color.g)))
			bitmask += 1u << 7u;
		if (read_keyed_float(*line, "    color_b:", &(plane->material.color.b)))
			bitmask += 1u << 8u;
		if (read_keyed_float(*line, "    specular:", &(plane->material.specular)))
			bitmask += 1u << 12u;
		i++;
		ft_memdel((void**)line);
	}
	if (bitmask != ((1u << 13u) - 1) || i != 13)
	{
		ft_memdel((void **)&plane);
		rtv_error(INVALIDE_STRUCT);
	}
	plane->angle = (t_vec3){0.0f, 0.0f, 0.0f};
	plane->material.color = float_to_byte(plane->material.color);
	return (plane);
}
