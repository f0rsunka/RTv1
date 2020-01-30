/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:38:30 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/30 18:40:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_sdl(t_sdl *sdl)
{
	printf("boop\n");
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("sdl init failed!\n");
		exit(99);
	}
	printf("SDL_INIT was creation\n");
	sdl->window = SDL_CreateWindow("RTV1", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!sdl->window)
	{
		exit(98);
	}
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
	if (!sdl->renderer)
	{
		exit(97);
	}
}

void	destroy_sdl(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}

void	clear_window_sdl(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0xFF); // задание цвета фона
    SDL_RenderClear(sdl->renderer);
}
