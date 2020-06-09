/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:08:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/09 17:06:47 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_rtv(t_rtv *rtv)
{
	(((WIN_W <= 0) || (WIN_H <= 0)) ? rtv_error(WINDOW_MIN) : 0);
	(((WIN_W > 1100) || (WIN_H > 1000)) ? rtv_error(WINDOW_MAX) : 0);
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

    if (ac != 2)
    {
        write(1, "Invalid arguments number, expected 1 argument for *.rtv1 scene file!\n", 69);
        exit(1);
    }
    rtv = (t_rtv *) malloc(sizeof(t_rtv));
    (rtv == NULL ? exit(99) : 1);
	read_scene(rtv, av[1]);
    init_rtv(rtv);
    main_render(rtv);
    return (0);

}
