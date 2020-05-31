/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:14:40 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/05/31 17:51:32 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		move(t_rtv *r)
{
	(r->sdl.event.key.keysym.sym == SDLK_e ? ((r->camera.y += 0.5) && (r->flag.is_move = 1)) : 0);
	(r->sdl.event.key.keysym.sym == SDLK_q ? ((r->camera.y -= 0.5) && (r->flag.is_move = 1)) : 0);
	(r->sdl.event.key.keysym.sym == SDLK_d ? ((r->camera.x -= 0.5) && (r->flag.is_move = 1)) : 0);
	(r->sdl.event.key.keysym.sym == SDLK_a ? ((r->camera.x += 0.5) && (r->flag.is_move = 1)) : 0);
	(r->sdl.event.key.keysym.sym == SDLK_w ? ((r->camera.z += 0.5) && (r->flag.is_move = 1)) : 0);
	(r->sdl.event.key.keysym.sym == SDLK_s ? ((r->camera.z -= 0.5) && (r->flag.is_move = 1)) : 0);
	return (r->flag.is_move);
}

int		rotation(t_rtv *r)
{
	(r->sdl.event.key.keysym.sym == SDLK_UP ? ((r->ray.angle.x -= 10.0f) && (r->flag.is_rotate = 1)) : 0);
	(r->sdl.event.key.keysym.sym == SDLK_DOWN ? ((r->ray.angle.x += 10.0f) && (r->flag.is_rotate = 1)) : 0);
	(r->sdl.event.key.keysym.sym == SDLK_LEFT ? ((r->ray.angle.y += 10.0f) && (r->flag.is_rotate = 1)) : 0);
	(r->sdl.event.key.keysym.sym == SDLK_RIGHT ? ((r->ray.angle.y -= 10.0f) && (r->flag.is_rotate = 1)) : 0);
	return (r->flag.is_rotate);
}

void	events(t_rtv *r)
{
	((move(r) || rotation(r) == 1) ? render(r) : 0);
	init_flags(&r->flag);
}
