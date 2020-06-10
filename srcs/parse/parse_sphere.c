/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:41:46 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 19:42:14 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*create_sphere(int fd, char **line)
{
	t_sphere	*sphere;
	int		status;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	sphere = (t_sphere *) malloc(sizeof(t_sphere));
	(sphere == NULL ? rtv_error(MALLOC_ERROR) : 0);
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
		if (read_keyed_double(*line, "    center_x:", &(sphere->center.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    center_y:", &(sphere->center.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    center_z:", &(sphere->center.z)))
			bitmask += 1u << 2u;
		if (read_keyed_float(*line, "    radius:", &(sphere->radius)))
		{
			bitmask += 1u << 3u;
			sphere->radius /= 100;
		}
		if (read_keyed_float(*line, "    color_r:", &(sphere->material.color.r)))
			bitmask += 1u << 4u;
		if (read_keyed_float(*line, "    color_g:", &(sphere->material.color.g)))
			bitmask += 1u << 5u;
		if (read_keyed_float(*line, "    color_b:", &(sphere->material.color.b)))
			bitmask += 1u << 6u;
		if (read_keyed_float(*line, "    specular:", &(sphere->material.specular)))
			bitmask += 1u << 7u;
		if (read_keyed_double(*line, "    angle_x:", &(sphere->angle.x)))
			bitmask += 1u << 8u;
		if (read_keyed_double(*line, "    angle_y:", &(sphere->angle.y)))
			bitmask += 1u << 9u;
		if (read_keyed_double(*line, "    angle_z:", &(sphere->angle.z)))
			bitmask += 1u << 10u;
		i++;
		ft_memdel((void**)line);
	}
	if (bitmask != ((1u << 11u) - 1) || i != 11)
	{
		ft_memdel((void **)&sphere);
		rtv_error(INVALIDE_STRUCT);
	}
	sphere->material.color = float_to_byte(sphere->material.color);
	return (sphere);
}
