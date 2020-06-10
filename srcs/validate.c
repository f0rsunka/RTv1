/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:57:23 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 13:31:46 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	if ((coef.x > 1 || coef.x < 0) || (coef.y > 1 || coef.y < 0)
											|| (coef.z > 1 || coef.z < 0))
		rtv_error(CYL_COEF_NOT_VALID);
}

void	check_radius(float r)
{
	if (r <= 0)
		rtv_error(NEGATIVE_VAL_RADIUS);
	if (r >= 1000)
		rtv_error(MAX_VAL_RADIUS);
}

void	check_material(t_material mat)
{
	if (mat.specular >= 1000)
		rtv_error(SPECULAR_OVERFLOW);
	if (mat.color.r > 255 || mat.color.g > 255 || mat.color.b > 255)
		rtv_error(COLOR_OVERFLOW);
	if (mat.color.r < 0 || mat.color.g < 0 || mat.color.b < 0)
		rtv_error(COLOR_NOT_ENOUGH);
}

void	check_coefficients_cone(t_vec3 coef)
{
	if (coef.x <= 0 || coef.y <= 0 || coef.z <= 0)
		rtv_error(CONE_COEF_DELIM_ZERO);
	if (coef.x < coef.y)
		rtv_error(CONE_COEF_NOT_VALID);
}

void	check_normal_plane(t_vec3 normal)
{
	if (normal.x == 0 && normal.y == 0 && normal.z == 0)
		rtv_error(PLANE_NORMAL_ZERO);
}
