/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:00:15 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/12 20:34:42 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://habr.com/ru/post/342510/
// https://habr.com/ru/post/436790/

#include "rtv1.h"

void render_sphere(t_rtv *r)
{
	t_ivec2	iter;
	t_vec2 	coord;
	t_vec3	dir;

	iter = (t_ivec2){0, 0};
	coord = (t_vec2){0.0f, 0.0f};
	while (iter.y < WIN_H)
	{
		iter.x = 0;
		while (iter.x < WIN_W)
		{
			coord.x =  (2 * (iter.x + 0.5) / (float)WIN_W - 1) * tan(FOV / 2.0) * WIN_W / (float)WIN_H;
            coord.y = -(2 * (iter.y + 0.5) / (float)WIN_H - 1) * tan(FOV / 2.0);
			dir = vec_normalize((t_vec3){coord.x, coord.y, -1});
			r->mlx.img[iter.x + iter.y * WIN_W] = get_color(cast_ray(r->camera, dir, r));
			iter.x++;
		}
		iter.y++;
	}
}
