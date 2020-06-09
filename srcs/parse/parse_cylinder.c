/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:38:10 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 19:49:06 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cylinder	*create_cylinder(int fd, char **line)
{
	t_cylinder	*cylinder;
	int			status;
	short		bitmask;
	size_t		i;

	bitmask = 0;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	(cylinder == NULL ? rtv_error(MALLOC_ERROR) : 0);
	ft_memdel((void**)line);
	i = 0;
	while ((status = get_next_line(fd, line)) > 0)
	{
		if (!**line)
		{
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break;
		((status == -1) ? rtv_error(READ_ERROR) : 0);
		if (read_keyed_double(*line, "    offset_x:", &(cylinder->offset.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    offset_y:", &(cylinder->offset.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    offset_z:", &(cylinder->offset.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    coef_x:", &(cylinder->coef.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    coef_y:", &(cylinder->coef.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    coef_z:", &(cylinder->coef.z)))
			bitmask += 1u << 5u;
		if (read_keyed_double(*line, "    angle_x:", &(cylinder->angle.x)))
			bitmask += 1u << 6u;
		if (read_keyed_double(*line, "    angle_y:", &(cylinder->angle.y)))
			bitmask += 1u << 7u;
		if (read_keyed_double(*line, "    angle_z:", &(cylinder->angle.z)))
			bitmask += 1u << 8u;
		if (read_keyed_float(*line, "    color_r:", &(cylinder->material.color.r)))
			bitmask += 1u << 9u;
		if (read_keyed_float(*line, "    color_g:", &(cylinder->material.color.g)))
			bitmask += 1u << 10u;
		if (read_keyed_float(*line, "    color_b:", &(cylinder->material.color.b)))
			bitmask += 1u << 11u;
		if (read_keyed_float(*line, "    specular:", &(cylinder->material.specular)))
			bitmask += 1u << 12u;
		if (read_keyed_float(*line, "    radius:", &(cylinder->radius))) {
			bitmask += 1u << 13u;
			cylinder->radius /= 100;
		}
		i++;
	}
	if (bitmask != ((1u << 14u) - 1) || i != 14)
	{
		ft_memdel((void **)&cylinder);
		rtv_error(INVALIDE_STRUCT);
	}
	cylinder->material.color = float_to_byte(cylinder->material.color);
	return (cylinder);
}
