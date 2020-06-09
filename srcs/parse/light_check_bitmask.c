/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check_bitmask.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 01:35:25 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 02:03:07 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		pos_check_keyed_double(short *bitmask, char *line,
																t_light *light)
{
	if (read_keyed_double(line, "    position_x:", &(light->position.x)))
		*bitmask += 1u << 0u;
	if (read_keyed_double(line, "    position_y:", &(light->position.y)))
		*bitmask += 1u << 1u;
	if (read_keyed_double(line, "    position_z:", &(light->position.z)))
		*bitmask += 1u << 2u;
}

static void		dir_check_keyed_double(short *bitmask, char *line,
																t_light *light)
{
	if (read_keyed_double(line, "    direction_x:", &(light->direction.x)))
		*bitmask += 1u << 3u;
	if (read_keyed_double(line, "    direction_y:", &(light->direction.y)))
		*bitmask += 1u << 4u;
	if (read_keyed_double(line, "    direction_z:", &(light->direction.z)))
		*bitmask += 1u << 5u;
}

static void		intensity_check_keyed_float(short *bitmask, char *line,
																t_light *light)
{
	if (read_keyed_float(line, "    intensity:", &(light->intensity)))
	{
		*bitmask += 1u << 6u;
		light->intensity /= 100;
	}
}

static void		type_check_keyed_int(short *bitmask, char *line,
																t_light *light)
{
	if (read_keyed_int(line, "    type:", &(light->type)))
		*bitmask += 1u << 7u;
}

size_t			light_check_bitmask(short *bitmask, t_light *light, char **line,
																	int fd)
{
	size_t	i;
	int		status;

	i = 0;
	while ((status = get_next_line(fd, line)))
	{
		if (!**line)
		{
			ft_memdel((void**)line);
			continue;
		}
		if (ft_strncmp(*line, "    ", 4))
			break ;
		((status == -1) ? rtv_error(READ_ERROR) : 0);
		pos_check_keyed_double(bitmask, *line, light);
		dir_check_keyed_double(bitmask, *line, light);
		intensity_check_keyed_float(bitmask, *line, light);
		type_check_keyed_int(bitmask, *line, light);
		i++;
	}
	return (i);
}
