/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:42:26 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 19:42:42 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone		*create_cone(int fd, char **line)
{
	t_cone	*cone;
	int		status;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	cone = (t_cone *)malloc(sizeof(t_cone));
	(cone == NULL ? rtv_error(MALLOC_ERROR) : 0);
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
		if (read_keyed_double(*line, "    offset_x:", &(cone->offset.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    offset_y:", &(cone->offset.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    offset_z:", &(cone->offset.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    coef_x:", &(cone->coef.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    coef_y:", &(cone->coef.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    coef_z:", &(cone->coef.z)))
			bitmask += 1u << 5u;
		if (read_keyed_double(*line, "    angle_x:", &(cone->angle.x)))
			bitmask += 1u << 6u;
		if (read_keyed_double(*line, "    angle_y:", &(cone->angle.y)))
			bitmask += 1u << 7u;
		if (read_keyed_double(*line, "    angle_z:", &(cone->angle.z)))
			bitmask += 1u << 8u;
		if (read_keyed_float(*line, "    color_r:", &(cone->material.color.r)))
			bitmask += 1u << 9u;
		if (read_keyed_float(*line, "    color_g:", &(cone->material.color.g)))
			bitmask += 1u << 10u;
		if (read_keyed_float(*line, "    color_b:", &(cone->material.color.b)))
			bitmask += 1u << 11u;
		if (read_keyed_float(*line, "    specular:", &(cone->material.specular)))
			bitmask += 1u << 12u;
		i++;
	}
	if (bitmask != ((1u << 13u) - 1) || i != 13)
	{
		ft_memdel((void **)&cone);
		rtv_error(INVALIDE_STRUCT);
	}
	cone->material.color = float_to_byte(cone->material.color);
	return (cone);
}
