/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:17:34 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 17:20:16 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
** *********************************** **
** *********************************** **
**         arguments errors	           **
** *********************************** **
** *********************************** **
*/

# define MISS_ARG				0
# define TOO_MUCH_ARG			1

/*
** *********************************** **
** *********************************** **
**         windows errors	           **
** *********************************** **
** *********************************** **
*/

# define WINDOW_MIN				2
# define WINDOW_MAX				3

/*
** *********************************** **
** *********************************** **
**           malloc errors	           **
** *********************************** **
** *********************************** **
*/

# define MALLOC_ERROR			4

/*
** *********************************** **
** *********************************** **
**             light errors            **
** *********************************** **
** *********************************** **
*/

# define LIGHT_MIN				5
# define LIGHT_MAX				6

/*
** *********************************** **
** *********************************** **
**             primitive errors        **
** *********************************** **
** *********************************** **
*/

# define PRIMITIVES_MIN			7
# define PRIMITIVES_MAX			8
# define NEGATIVE_VAL_RADIUS	9
# define MAX_VAL_RADIUS			10
# define CYL_COEF_NOT_EXIST		11
# define CYL_COEF_ALL_EXISTS	12
# define CYL_COEF_NOT_ONE		13
# define CYL_COEF_NOT_VALID		14
# define CONE_COEF_NOT_VALID	15
# define CONE_COEF_DELIM_ZERO	16


# define SPECULAR_OVERFLOW		100

#endif