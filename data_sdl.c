/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:38:30 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/28 15:40:26 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

SDL_Renderer	*init_sdl(t_sdl *sdl)
{
	SDL_Window		*window = nullptr;
	SDL_Renderer	*renderer = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		// std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		exit(99);
	}
	window = SDL_CreateWindow("Draw line", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		// std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		exit(98);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		// std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		exit(97);
	}
	renderer = SDL_GetRenderer(window);
    if (renderer == nullptr)
	{
        // std::cerr << "SDL_GetRenderer Error: " << SDL_GetError() << std::endl;
       exit(96);
    }
	return(renderer);
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
