/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:08:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 18:06:16 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere *create_mas(void)
{
	t_sphere *mas;
	if (!(mas = (t_sphere*)malloc(sizeof(t_sphere) * 3)))
		return (NULL);
	return (mas);
}

int		main(void)
{
	t_sphere *mas_sphere;
	t_sdl *sdl;
	int finished;
	int i = 0;

	mas_sphere = create_mas();
	printf("%p\n", mas_sphere);
	mas_sphere[0] = (t_sphere){(t_vector3d){0, -1, 3}, 1.0, (t_color){255, 0, 0}};
	printf("\n%p\n", mas_sphere[i]);
	mas_sphere[1] = new_sphere((t_vector3d){2, 0, 4}, 1.0, (t_color){0, 0, 255});
	mas_sphere[2] = new_sphere((t_vector3d){-2, 0, 4}, 1.0, (t_color){0, 255, 0});
	printf("%f\n%f\n%f\n", mas_sphere[0].center.x, mas_sphere[0].center.y, mas_sphere[0].center.z);
	finished = 0;
	sdl = malloc(sizeof(t_sdl));
	sdl->event = (SDL_Event){0};
	init_sdl(sdl);
	printf("SDL was initialized\n");
	if (sdl->renderer)
	{
		while (!finished)
		{
			clear_window_sdl(sdl);
			rtv_test(sdl, &mas_sphere[0]);
			printf("RTV_TEST_SUCCESSED\n");
			SDL_RenderPresent(sdl->renderer);
			while (SDL_PollEvent(&sdl->event))
			{
				if (sdl->event.type == SDL_QUIT)
					finished = 1;
			}
		}
		destroy_sdl(sdl);
	}
	else
		exit(90);
	return (0);
}
