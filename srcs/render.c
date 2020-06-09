/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:00:15 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/09 13:09:41 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	zero_all(t_ray *ray, t_trace *trace)
{
	ray_zero(ray);
	trace_zero(trace);
}

void	render(t_rtv *r)
{
	t_ivec2	iter;
	t_vec2	coord;
	t_color color;

	iter = (t_ivec2){0, 0};
	coord = (t_vec2){0.0f, 0.0f};
	while (iter.y < WIN_H)
	{
		iter.x = 0;
		while (iter.x < WIN_W)
		{
			zero_all(&r->ray, &r->trace);
			coord.x = (2 * (iter.x + 0.5) /
					(float)WIN_W - 1) * tan(FOV / 2.0) * WIN_W / (float)WIN_H;
			coord.y = (2 * (iter.y + 0.5) / (float)WIN_H - 1) * tan(FOV / 2.0);
			r->ray.dir = vec_normalize((t_vec3){coord.x, coord.y, -1});
			rotate(&r->ray.dir, r->ray.angle);
			r->trace = (t_trace){r->camera, r->ray.dir, 0.0f, FLT_MAX};
			color = trace_ray(r).color;
			color = byte_to_float(color);
			put_pixel(r->sdl.renderer, iter.x, iter.y, color);
			iter.x++;
		}
		iter.y++;
	}
}
