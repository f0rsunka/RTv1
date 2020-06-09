/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:38:01 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 15:35:31 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	arguments_errors(int n)
{
	if (n == 0)
		write_error("RTv1: missing argument after call\n"\
							"usage: ./RTv1 scenes/[file]\n");
	if (n == 1)
		write_error("RTv1: too much arguments, expected one\n"\
							"usage: ./RTv1 scenes/[file]\n");
}

void	window_errors(int n)
{
	if (n == 2)
		write_error("RTv1: too small window.\n");
	if (n == 3)
		write_error("RTv1: too big window.\n");
}


void	malloc_error(int n)
{
	if (n == 4)
		write_error("RTv1: memory allocation error.\n");
}

void	lights_errors(int n)
{
	if (n == 5)
		write_error("RTv1: too much count of lights.\n");
	if (n == 6)
		write_error("RTv1: too few count of lights.\n");
}

void	primitives_errors(int n)
{
	if (n == 7)
		write_error("RTv1: too few count of primitives.\n");
	if (n == 8)
		write_error("RTv1: too much count of primitives.\n");
	if (n == 9)
		write_error("RTv1: primitive's radius can't be negative.\n");
	if (n == 10)
		write_error("RTv1: all cylinder's coefficients can't be equal to zero.\n\
					Only one axis (x, y or z) can be equal to 0.");
	if (n == 11)
		write_error("RTv1: all cylinder's coefficients can't be equal to one.\n\
					One axis (x, y or z) should be equal to 0.");
	if (n == 12)
		write_error("RTv1: Two axis should be exists, \
					it means two axis should be equals to one.\n");
}
