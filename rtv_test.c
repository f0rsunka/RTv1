/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:00:15 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/27 21:04:55 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector3d *canvas_to_viweport(t_vector2d coord, t_vector2d v)
{
	t_vector3d *D;

	D->x = coord.x * v.x / WIDTH;
	D->y = coord.y * v.y / HEIGHT;
	D->z = d;
	// D = (t_vector3d*){(coord.x * v.x / WIDTH), (coord.y * v.y / HEIGHT), d};
	return (D);
}

void	rtv_test()
{
	t_vector3d *camera;
	t_vector3d *D;
	t_vector2d viewport;
	t_vector2d coord;

	camera = malloc(sizeof(t_vector3d));
	camera = (t_vector3d *){0, 0, 0};
	coord = (t_vector2d){- WIDTH / 2,  - HEIGHT / 2};
	viewport = (t_vector2d){1, 1};
	while (coord.x < WIDTH / 2)
	{
		while (coord.y < HEIGHT / 2)
		{
			D = canvas_to_viewport(coord, viewport);
			color = trace_ray(camera, D, 1, t_max);
			canvas.putpixel(coord, color);
		}
	}

}