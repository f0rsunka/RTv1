/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:17:34 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 20:53:52 by f0rsunka         ###   ########.fr       */
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
# define DIRECTORY_ERR			2
# define CLOSE_FD_ERROR			3
# define NOT_A_FILE				4

/*
** *********************************** **
** *********************************** **
**         validate errors	           **
** *********************************** **
** *********************************** **
*/

# define GNL_ERROR				5
# define READ_ERROR				6
# define OBJ_ERROR				7
# define LIGHTS_ERROR			8
# define INVALIDE_STRUCT		9
# define WINDOW_MIN				10
# define WINDOW_MAX				11

/*
** *********************************** **
** *********************************** **
**           malloc errors	           **
** *********************************** **
** *********************************** **
*/

# define MALLOC_ERROR			12

/*
** *********************************** **
** *********************************** **
**             light errors            **
** *********************************** **
** *********************************** **
*/

# define LIGHT_MIN				13
# define LIGHT_MAX				14

/*
** *********************************** **
** *********************************** **
**             primitive errors        **
** *********************************** **
** *********************************** **
*/

# define PRIMITIVES_MIN			15
# define PRIMITIVES_MAX			16
# define NEGATIVE_VAL_RADIUS	17
# define MAX_VAL_RADIUS			18
# define CYL_COEF_NOT_EXIST		19
# define CYL_COEF_ALL_EXISTS	20
# define CYL_COEF_NOT_ONE		21
# define CYL_COEF_NOT_VALID		22
# define CONE_COEF_NOT_VALID	23
# define CONE_COEF_DELIM_ZERO	24
# define SPECULAR_OVERFLOW		25

#endif
