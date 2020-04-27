/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 22:22:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/26 22:28:57 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_pixel(SDL_Renderer *ren, int x, int y, t_color col)
{
	int r;
	int g;
	int b;

	r = floor(col.r);
	g = floor(col.g);
	b = floor(col.b);
	if (x < WIN_W && y < WIN_H)
	{
		SDL_SetRenderDrawColor(ren, r, g, b, 0xFF);
		// SDL_SetRenderDrawColor(ren, col.r, col.g, col.b, 0xFF);
		SDL_RenderDrawPoint(ren, x, y);
	}
}
