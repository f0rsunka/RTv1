/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:14:23 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/05/31 17:14:25 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_x(t_ray *ray)
{
	ray->dir.x = ray->dir.x;
	ray->dir.y = cos(ray->angle.x * DEG2RAD) * ray->dir.y + (-sin(ray->angle.x * DEG2RAD)) * ray->dir.z;
	ray->dir.z = sin(ray->dir.x * DEG2RAD) * ray->dir.y + cos(ray->angle.x * DEG2RAD) * ray->dir.z;
}

void	rotate_y(t_ray *ray)
{
	ray->dir.x = ray->dir.x * cos(ray->angle.y * DEG2RAD) + ray->dir.z * sin(ray->angle.y * DEG2RAD);
	ray->dir.y = ray->dir.y;
	ray->dir.z = ray->dir.x * (-sin(ray->angle.y * DEG2RAD)) + ray->dir.z * cos(ray->angle.y * DEG2RAD);
}

void	rotate_z(t_ray *ray)
{
	ray->dir.x = cos(ray->angle.z * DEG2RAD) * ray->dir.x + (-sin(ray->angle.z * DEG2RAD)) * ray->dir.y;
	ray->dir.y = sin(ray->angle.z * DEG2RAD) * ray->dir.x + ray->dir.y * cos(ray->angle.z * DEG2RAD);
	ray->dir.z = ray->dir.z;
}

void	rotate(t_ray *ray)
{
	rotate_x(ray);
	rotate_y(ray);
	rotate_z(ray);
}
