/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:38:30 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 22:25:44 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sdl_error(void)
{
	ft_putstr_fd(SDL_GetError(), 2);
	exit(99);
}

t_sdl	init_sdl(void)
{
	t_sdl sdl;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		sdl_error();
	sdl.window = SDL_CreateWindow("RTV1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
	if (!sdl.window)
		sdl_error();
	sdl.renderer = SDL_CreateRenderer(sdl.window, -1, SDL_RENDERER_ACCELERATED);
	if (!sdl.renderer)
		sdl_error();
	return (sdl);
}

void	destroy_sdl(t_sdl sdl)
{
	SDL_DestroyRenderer(sdl.renderer);
	SDL_DestroyWindow(sdl.window);
	SDL_Quit();
}

void	clear_window_sdl(t_sdl sdl)
{
	SDL_SetRenderDrawColor(sdl.renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, 0xFF);
    SDL_RenderClear(sdl.renderer);
}
