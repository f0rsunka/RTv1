/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value_primitive.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:37:55 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 17:17:28 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv1.h"

void	check_coefficients_cyl(t_vec3 coef)
{
	if (coef.x == 0 && coef.y == 0 && coef.z == 0)
		rtv_error(CYL_COEF_NOT_EXIST);
	if (coef.x == 1 && coef.y == 1 && coef.z == 1)
		rtv_error(CYL_COEF_ALL_EXISTS);
	if ((coef.x == 0 && coef.y == 0 && coef.z == 1) ||
		(coef.x == 0 && coef.y == 1 && coef.z == 0) ||
		(coef.x == 1 && coef.y == 0 && coef.z == 0))
		rtv_error(CYL_COEF_NOT_ONE);
	// if ((coef.x > 1 || coef.x < 0) || (coef.y > 1 || coef.y < 0)
	// 										|| (coef.z > 1 || coef.z < 0))
	// 	rtv_error(CYL_COEF_NOT_VALID);
}

void	check_radius(float r)
{
	if (r <= 0)
		rtv_error(NEGATIVE_VAL_RADIUS);
	if (r >= FLT_MAX)
		rtv_error(MAX_VAL_RADIUS);
}

void	check_specular(float s)
{
	if (s >= 10000)
		rtv_error(SPECULAR_OVERFLOW);
}

void	check_coefficients_cone(t_vec3 coef)
{
	if (coef.x <= 0 || coef.y <= 0 || coef.z <= 0)
		rtv_error(CONE_COEF_DELIM_ZERO);
	if (coef.x < coef.y)
		rtv_error(CONE_COEF_NOT_VALID);	
}
