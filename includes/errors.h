/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:17:34 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/11 02:02:18 by f0rsunka         ###   ########.fr       */
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
# define TOO_MUCH_ARG			MISS_ARG + 1
# define DIRECTORY_ERR			TOO_MUCH_ARG + 1
# define CLOSE_FD_ERROR			DIRECTORY_ERR + 1
# define NOT_A_FILE				CLOSE_FD_ERROR + 1

/*
** *********************************** **
** *********************************** **
**         validate errors	           **
** *********************************** **
** *********************************** **
*/

# define GNL_ERROR				NOT_A_FILE + 1
# define READ_ERROR				GNL_ERROR + 1
# define OBJ_ERROR				READ_ERROR + 1
# define LIGHTS_ERROR			OBJ_ERROR + 1
# define INVALIDE_STRUCT		LIGHTS_ERROR + 1
# define WINDOW_MIN				INVALIDE_STRUCT + 1
# define WINDOW_MAX				WINDOW_MIN + 1
# define PRIMITIVES_MIN			WINDOW_MAX + 1
# define PRIMITIVES_MAX			PRIMITIVES_MIN + 1

/*
** *********************************** **
** *********************************** **
**           malloc errors	           **
** *********************************** **
** *********************************** **
*/

# define MALLOC_ERROR			PRIMITIVES_MAX + 1

/*
** *********************************** **
** *********************************** **
**             light errors            **
** *********************************** **
** *********************************** **
*/

# define LIGHT_MIN				MALLOC_ERROR + 1
# define LIGHT_MAX				LIGHT_MIN + 1
# define INTENSITY_NOT_ENOUGH	LIGHT_MAX + 1
# define INTENSITY_TOO_MUCH		INTENSITY_NOT_ENOUGH + 1

/*
** *********************************** **
** *********************************** **
**             primitive errors        **
** *********************************** **
** *********************************** **
*/

# define NEGATIVE_VAL_RADIUS	INTENSITY_TOO_MUCH + 1
# define MAX_VAL_RADIUS			NEGATIVE_VAL_RADIUS + 1
# define CYL_COEF_NOT_EXIST		MAX_VAL_RADIUS + 1
# define CYL_COEF_ALL_EXISTS	CYL_COEF_NOT_EXIST + 1
# define CYL_COEF_NOT_ONE		CYL_COEF_ALL_EXISTS + 1
# define CYL_COEF_NOT_VALID		CYL_COEF_NOT_ONE + 1
# define CONE_COEF_NOT_VALID	CYL_COEF_NOT_VALID + 1
# define CONE_COEF_DELIM_ZERO	CONE_COEF_NOT_VALID + 1
# define PLANE_NORMAL_ZERO		CONE_COEF_DELIM_ZERO + 1

/*
** *********************************** **
** *********************************** **
**             material errors         **
** *********************************** **
** *********************************** **
*/

# define SPECULAR_OVERFLOW		PLANE_NORMAL_ZERO + 1
# define COLOR_OVERFLOW			SPECULAR_OVERFLOW + 1
# define COLOR_NOT_ENOUGH		COLOR_OVERFLOW + 1

#endif
