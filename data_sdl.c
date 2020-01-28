/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:38:30 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/28 20:09:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

SDL_Renderer	*init_sdl(t_sdl *sdl)
{
	sdl->window = 0;
	sdl->renderer = 0;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		exit(99);
	}
	sdl->window = SDL_CreateWindow("Draw line", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!sdl->window)
	{
		exit(98);
	}
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!sdl->renderer)
	{
		exit(97);
	}
	sdl->renderer = SDL_GetRenderer(sdl->window);
    if (!sdl->renderer)
	{
       exit(96);
    }
	return(sdl->renderer);
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
