/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:08:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/28 17:44:41 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere *create_mas(void)
{
	t_sphere *mas_sphere;

	if (!(mas_sphere = (t_sphere*)ft_memalloc(sizeof(t_sphere) * 2)))
		return (NULL);
	return (mas_sphere);
}

t_sphere	*get_data_sphere()
{
	t_sphere *mas;
	
	mas = create_mas();
	mas[0].center = (t_vector3d){0, -1, 3};
	mas[0].radius = 1;
	mas[0].color = (t_vector3d){255, 0, 0};
	
	mas[1].center = (t_vector3d){2, 0, 4};
	mas[1].radius = 1;
	mas[1].color = (t_vector3d){0, 0, 255};
	
	mas[2].center = (t_vector3d){-2, 0, 4};
	mas[2].radius = 1;
	mas[2].color = (t_vector3d){0, 255, 0};
	return (mas);
}

int		main(void)
{
	t_sphere *mas_s;
	t_sdl *sdl;
	int finished;

	mas_s = get_data_sphere();
	finished = 0;
	sdl = (t_sdl*)malloc(sizeof(t_sdl*));
	sdl->renderer = init_sdl(sdl);
	if (sdl->renderer)
	{
		clear_window_sdl(sdl);
		rtv_test(sdl, mas_s);
		SDL_RenderPresent(sdl->renderer);
		while (SDL_PollEvent(&sdl->event))
		{
			if (sdl->event.type == SDL_QUIT)
				finished = 0;
		}
		destroy_sdl(sdl);
	}
	else
		exit(90);
	return (0);
}
