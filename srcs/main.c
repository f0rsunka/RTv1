/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:08:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/07 15:14:11 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_rtv(t_rtv *rtv)
{
	// проверка размера окна - мб функция тут должна быть? в файле с ошибками будет лежать
	// (WIN_W <= 0 ? exit(99) : 0);
	// (WIN_H <= 0 ? exit(99) : 0);
	rtv->light = init_light();
	init_primitives(rtv);
	init_camera(rtv);
	init_flags(&rtv->flag);
	ray_zero(&rtv->ray);
	trace_zero(&rtv->trace);
	rtv->sdl = init_sdl();
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
