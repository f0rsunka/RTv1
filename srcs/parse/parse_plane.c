/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:43:12 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 11:40:45 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane	*create_plane(int fd, char **line)
{
	t_plane	*plane;
	short	bitmask;
	size_t	i;

	bitmask = 0;
	plane = (t_plane *)malloc(sizeof(t_plane));
	ft_memdel((void**)line);
	i = plane_check_bitmask(&bitmask, plane, line, fd);
	if (bitmask != ((1u << 13u) - 1) || i != 13)
	{
		ft_memdel((void **)&plane);
		rtv_error(INVALIDE_STRUCT);
	}
	plane->angle = (t_vec3){0.0f, 0.0f, 0.0f};
	plane->material.color = float_to_byte(plane->material.color);
	return (plane);
}
