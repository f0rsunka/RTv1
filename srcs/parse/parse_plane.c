/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:43:12 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 12:33:55 by f0rsunka         ###   ########.fr       */
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
	(plane == NULL ? rtv_error(MALLOC_ERROR) : 0);
	ft_memdel((void**)line);
	i = plane_check_bitmask(&bitmask, plane, line, fd);
	if (bitmask != ((1u << 13u) - 1) || i != 13)
	{
		ft_memdel((void **)&plane);
		rtv_error(INVALIDE_STRUCT);
	}
	check_normal_plane(plane->normal);
	check_specular(plane->material.specular);
	plane->angle = (t_vec3){0.0f, 0.0f, 0.0f};
	plane->material.color = float_to_byte(plane->material.color);
	return (plane);
}
