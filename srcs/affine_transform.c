/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:14:23 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 11:37:32 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_x(t_vec3 *vec, t_vec3 angle)
{
	vec->x = vec->x;
	vec->y = cos(angle.x * DEG2RAD) * vec->y +
											(-sin(angle.x * DEG2RAD)) * vec->z;
	vec->z = sin(angle.x * DEG2RAD) * vec->y + cos(angle.x * DEG2RAD) * vec->z;
}

void	rotate_y(t_vec3 *vec, t_vec3 angle)
{
	vec->x = vec->x * cos(angle.y * DEG2RAD) + vec->z * sin(angle.y * DEG2RAD);
	vec->y = vec->y;
	vec->z = vec->x * (-sin(angle.y * DEG2RAD)) +
											vec->z * cos(angle.y * DEG2RAD);
}

void	rotate_z(t_vec3 *vec, t_vec3 angle)
{
	vec->x = cos(angle.z * DEG2RAD) * vec->x +
											(-sin(angle.z * DEG2RAD)) * vec->y;
	vec->y = sin(angle.z * DEG2RAD) * vec->x + vec->y * cos(angle.z * DEG2RAD);
	vec->z = vec->z;
}

void	rotate(t_vec3 *vec, t_vec3 angle)
{
	rotate_x(vec, angle);
	rotate_y(vec, angle);
	rotate_z(vec, angle);
}
