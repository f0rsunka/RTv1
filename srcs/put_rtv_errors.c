/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rtv_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:23:01 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 21:59:39 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	write_error(char *reason)
{
	ft_putstr_fd(reason, 2);
	// int	i;

	// i = 0;
	// while (reason[i])
	// 	i++;
	// write(1, &reason, i);
}

void	rtv_error(int n)
{
	if (n >= MISS_ARG && n <= NOT_A_FILE)
		arguments_errors(n);
	if (n >= GNL_ERROR && n <= WINDOW_MAX)
		validate_errors(n);
	if (n == MALLOC_ERROR)
		malloc_error(n);
	if (n >= LIGHT_MIN && n <= LIGHT_MAX)
		lights_errors(n);
	if (n >= PRIMITIVES_MIN && n <= SPECULAR_OVERFLOW)
		primitives_errors(n);
	ft_putstr_fd("Oh no...it was a mistake (≧◡≦)\n", 1);
	exit(0);
}
