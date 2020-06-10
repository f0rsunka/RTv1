/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:41:46 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 12:38:43 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*create_sphere(int fd, char **line)
{
	t_sphere	*sphere;
	short		bitmask;
	size_t		i;

	bitmask = 0;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	(sphere == NULL ? rtv_error(MALLOC_ERROR) : 0);
	ft_memdel((void**)line);
	i = sphere_check_bitmask(&bitmask, sphere, line, fd);
	if (bitmask != ((1u << 11u) - 1) || i != 11)
	{
		ft_memdel((void **)&sphere);
		rtv_error(INVALIDE_STRUCT);
	}
	check_radius(sphere->radius);
	check_specular(sphere->material.specular);
	sphere->material.color = float_to_byte(sphere->material.color);
	return (sphere);
}
