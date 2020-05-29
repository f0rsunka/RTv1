/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:08:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 15:33:54 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_rtv(t_rtv *rtv)
{
	init_primitive(rtv);
	rtv->light = init_light();
	rtv->sdl = init_sdl();
	init_camera(rtv);
	init_flags(rtv);
	ray_zero(&rtv->ray);
}

int		main_render(t_rtv *r)
{
	while (1)
	{
		// SDL_SetRenderTarget(r->sdl.renderer, NULL);
		clear_window_sdl(r->sdl);
		render(r);
		SDL_RenderPresent(r->sdl.renderer);
		while (SDL_PollEvent(&r->sdl.event))
		{
			if (r->sdl.event.type == SDL_KEYDOWN)
				events(r);
            if ((r->sdl.event.type == SDL_KEYDOWN &&
				 r->sdl.event.key.keysym.sym == SDLK_ESCAPE) ||
                (r->sdl.event.type == SDL_QUIT))
				exit(88);
		}
	}
	destroy_sdl(r->sdl);
	return (1);
}

int		main(void)
{
	t_rtv	*rtv;

	rtv = (t_rtv*)malloc(sizeof(t_rtv));
	(rtv == NULL ? exit (99) : 1);
	init_rtv(rtv);
	main_render(rtv);
	return (0);
}
