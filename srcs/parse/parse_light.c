/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:47:24 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 13:06:44 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parse_light(int fd, char **line, t_light *light)
{
	int		bitmask;
	size_t	i;

	bitmask = 0;
	ft_memdel((void**)line);
	i = light_check_bitmask(&bitmask, light, line, fd);
	if (bitmask != ((1u << 8u) - 1) || i != 8)
	{
		ft_memdel((void **)&light);
		ft_putendl_fd("Invalid struct!", 2);
		exit(1);
	}
	(light->intensity <= 0.0f ? rtv_error(INTENSITY_NOT_ENOUGH) : 0);
	(light->intensity >= 1.0 ? rtv_error(INTENSITY_TOO_MUCH) : 0);
}
