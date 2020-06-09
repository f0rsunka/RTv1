/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:47:24 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 20:24:34 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parse_light(int fd, char **line, t_light *light)
{
	int		status;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	ft_memdel((void**)line);
	i = 0;
	while ((status = get_next_line(fd, line))) {
		if (!**line) {
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break;
		((status == -1) ? rtv_error(READ_ERROR) : 0);
		if (read_keyed_double(*line, "    position_x:", &(light->position.x)))
			bitmask += 1u << 0u;
		if (read_keyed_double(*line, "    position_y:", &(light->position.y)))
			bitmask += 1u << 1u;
		if (read_keyed_double(*line, "    position_z:", &(light->position.z)))
			bitmask += 1u << 2u;
		if (read_keyed_double(*line, "    direction_x:", &(light->direction.x)))
			bitmask += 1u << 3u;
		if (read_keyed_double(*line, "    direction_y:", &(light->direction.y)))
			bitmask += 1u << 4u;
		if (read_keyed_double(*line, "    direction_z:", &(light->direction.z)))
			bitmask += 1u << 5u;
		if (read_keyed_float(*line, "    intensity:", &(light->intensity))) {
			bitmask += 1u << 6u;
			light->intensity /= 100;
		}
		if (read_keyed_int(*line, "    type:", &(light->type)))
			bitmask += 1u << 7u;
		i++;
	}
	if (bitmask != ((1u << 8u) - 1) || i != 8)
	{
		ft_memdel((void **)&light);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
}
