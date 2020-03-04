/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:00:15 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 22:25:44 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector3d *canvas_to_viewport(t_vector2d coord, t_viewport v)
{
	t_vector3d *D;

	D = (t_vector3d*)(malloc(sizeof(t_vector3d)));
	D->x = coord.x * v.w / WIN_W;
	D->y = coord.y * v.h / WIN_H;
	D->z = v.d;
	// D = (t_vector3d*){(coord.x * v.x / WIN_W), (coord.y * v.y / WIN_H), d};
	return (D);
}

void	rtv_test(t_sdl *sdl, t_sphere *mas_sphere)
{
	t_vector3d	camera;
	t_vector3d	*D;
	t_viewport	viewport;
	t_vector2d	coord;
	t_color		color;

	printf("Ya v rtv_test\n");
	printf("mas_sphere = %p\n", mas_sphere);
	// camera = (t_vector3d*)malloc(sizeof(t_vector3d));
	camera = (t_vector3d){0, 0, 0};
	coord = (t_vector2d){- WIN_W / 2,  - WIN_H / 2};
	viewport = (t_viewport){1, 1, 1};
	while (coord.x < WIN_W / 2)
	{
		coord.y = - WIN_H / 2;
		while (coord.y < WIN_H / 2)
		{
			D = canvas_to_viewport(coord, viewport);
			color = trace_ray(camera, D, 1, mas_sphere);
			printf("color === \n%d %d %d\n", color.r, color.g, color.b);
			SDL_SetRenderDrawColor(sdl->renderer, color.r, color.g, color.b, 0xFF);
			SDL_RenderDrawPoint(sdl->renderer, coord.x, coord.y);
			coord.y++;
		}
		coord.x++;
	}
}