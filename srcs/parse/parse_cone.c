/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:42:26 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 12:47:57 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone		*create_cone(int fd, char **line)
{
	t_cone	*cone;
	int		bitmask;
	size_t	i;

	bitmask = 0;
	cone = (t_cone *)malloc(sizeof(t_cone));
	(cone == NULL ? rtv_error(MALLOC_ERROR) : 0);
	ft_memdel((void**)line);
	i = cone_check_bitmask(&bitmask, cone, line, fd);
	if (bitmask != ((1u << 13u) - 1) || i != 13)
	{
		ft_memdel((void **)&cone);
		rtv_error(INVALIDE_STRUCT);
	}
	cone->coef = mult_vec(cone->coef, cone->coef);
	check_coefficients_cone(cone->coef);
	check_material(cone->material);
	cone->material.color = float_to_byte(cone->material.color);
	return (cone);
}
