/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:38:01 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 21:07:14 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	arguments_errors(int n)
{
	if (n == MISS_ARG)
		write_error("RTv1: missing argument after call\n"\
							"usage: ./RTv1 scenes/[file]\n");
	if (n == TOO_MUCH_ARG)
		write_error("RTv1: too much arguments, expected one\n"\
							"usage: ./RTv1 scenes/[file]\n");
	if (n == DIRECTORY_ERR)
		write_error("RTv1: scene can't be a directory!\n"\
							"RTv1: please check path\n");
	if (n == CLOSE_FD_ERROR)
		write_error("RTv1: fd close error\n");
	if (n == NOT_A_FILE)
		write_error("RTv1: can't open a scene\n");
}

void	validate_errors(int n)
{
	// if (n == GNL_ERROR)
	// 	write_error("RTv1: gnl == -1\n");
	if (n == GNL_ERROR || n == READ_ERROR)
		write_error("RTv1: read error\n");
	if (n == OBJ_ERROR)
		write_error("RTv1: дважды задана мажорная категория objects\n");
	if (n == LIGHTS_ERROR)
		write_error("RTv1: дважды задана мажорная категория lights\n");
	if (n == INVALIDE_STRUCT)
		write_error("RTv1: ошибка в структуре\n");
	if (n == WINDOW_MIN)
		write_error("RTv1: too small window.\n");
	if (n == WINDOW_MAX)
		write_error("RTv1: too big window.\n");
}

void	malloc_error(int n)
{
	if (n == MALLOC_ERROR)
		write_error("RTv1: memory allocation error.\n");
}

void	lights_errors(int n)
{
	if (n == LIGHT_MAX)
		write_error("RTv1: too much count of lights.\n");
	if (n == LIGHT_MIN)
		write_error("RTv1: too few count of lights.\n");
}

void	primitives_errors(int n)
{
	if (n == PRIMITIVES_MAX)
		write_error("RTv1: too few count of primitives.\n");
	if (n == PRIMITIVES_MIN)
		write_error("RTv1: too much count of primitives.\n");
	if (n == NEGATIVE_VAL_RADIUS)
		write_error("RTv1: primitive's radius can't be negative.\n");
	if (n == CYL_COEF_NOT_EXIST)
		write_error("RTv1: all cylinder's coefficients can't be equal to zero.\
					\nOnly one axis (x, y or z) can be equal to 0.\n");
	if (n == CYL_COEF_ALL_EXISTS)
		write_error("RTv1: all cylinder's coefficients can't be equal to one.\
					\nOne axis (x, y or z) should be equal to 0.\n");
	if (n == CYL_COEF_NOT_ONE)
		write_error("RTv1: only two axis should be exists, \
					it means two axis should be equals to 1 \
					and one axis should be equals to 0.\n");
	if (n == CYL_COEF_NOT_VALID)
		write_error("RTv1: all cylinder's coefficients can't be equal \
					to anything except 1 or 0.\n");
	if (n == CONE_COEF_NOT_VALID)
		write_error("RTv1: cone's coefficients cannot be negative.\n");
	if (n == CONE_COEF_DELIM_ZERO)
		write_error("RTv1: cone's coefficients cannot equal to 0.\n");
	if (n == SPECULAR_OVERFLOW)
		write_error("RTv1: specular's value is too big.\n");
}
