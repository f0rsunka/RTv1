/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:08:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/11 00:58:18 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_rtv(t_rtv *rtv)
{
	rtv->sdl = init_sdl();
	init_camera(rtv);
	init_flags(&rtv->flag);
	ray_zero(&rtv->ray);
	trace_zero(&rtv->trace);
}

int		main_render(t_rtv *r)
{
	while (1)
	{
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

int		main(int ac, char **av)
{
	t_rtv *rtv;

	check_read_file(ac, av);
	rtv = (t_rtv *)malloc(sizeof(t_rtv));
	(rtv == NULL ? rtv_error(MALLOC_ERROR) : 1);
	ft_bzero(rtv, sizeof(t_rtv));
	read_scene(rtv, av[1]);
	init_rtv(rtv);
	main_render(rtv);
	return (0);
}
