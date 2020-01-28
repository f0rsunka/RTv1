/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/28 19:54:22 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere *new_sphere(t_vector3d center, double radius, t_color color)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere*));
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}
