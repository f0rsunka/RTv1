/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:38:10 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 12:46:29 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cylinder	*create_cylinder(int fd, char **line)
{
	t_cylinder	*cylinder;
	short		bitmask;
	size_t		i;

	bitmask = 0;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	(cylinder == NULL ? rtv_error(MALLOC_ERROR) : 0);
	ft_memdel((void**)line);
	i = cylinder_check_bitmask(&bitmask, cylinder, line, fd);
	if (bitmask != ((1u << 14u) - 1) || i != 14)
	{
		ft_memdel((void **)&cylinder);
		rtv_error(INVALIDE_STRUCT);
	}
	check_coefficients_cyl(cylinder->coef);
	check_radius(cylinder->radius);
	check_material(cylinder->material);
	cylinder->material.color = float_to_byte(cylinder->material.color);
	return (cylinder);
}
