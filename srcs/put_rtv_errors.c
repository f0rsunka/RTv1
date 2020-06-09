/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rtv_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:23:01 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 15:33:30 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	write_error(char *reason)
{
	int	i;

	i = 0;
	while (reason[i])
		i++;
	write(1, reason, i);
}

void	rtv_error(int n)
{
	if (n == 0 || n == 1)
		arguments_errors(n);
	if (n == 2 || n == 3)
		window_errors(n);
	if (n == 4)
		malloc_error(n);
	if (n == 5 || n == 6)
		lights_errors(n);
	if (n >= 7 && n <= 12)
		primitives_errors(n);
	exit(0);
}
