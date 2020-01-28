/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/28 16:33:30 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_sphere *new_sphere(t_vector3d center, double radius, t_vector3d color)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere*));
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}
