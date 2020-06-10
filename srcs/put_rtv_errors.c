/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rtv_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:23:01 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 13:24:44 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	write_error(char *reason)
{
	ft_putstr_fd(reason, 2);
}

void	rtv_error(int n)
{
	if (n >= MISS_ARG && n <= NOT_A_FILE)
		arguments_errors(n);
	if (n >= GNL_ERROR && n <= PRIMITIVES_MAX)
		validate_errors(n);
	if (n == MALLOC_ERROR)
		write_error("RTv1: memory allocation error.\n");
	if (n >= LIGHT_MIN && n <= INTENSITY_TOO_MUCH)
		lights_errors(n);
	if (n >= NEGATIVE_VAL_RADIUS && n <= PLANE_NORMAL_ZERO)
		primitives_errors(n);
	if (n >= SPECULAR_OVERFLOW && n <= COLOR_NOT_ENOUGH)
		material_errors(n);
	ft_putstr_fd("(≧◡≦) Oh no...it was a mistake (≧◡≦)\n", 1);
	exit(0);
}
