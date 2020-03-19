/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:22:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 22:28:57 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_color(t_color color)
{
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}

void	put_pixel(SDL_Renderer *ren, int x, int y, t_color col)
{
	SDL_SetRenderDrawColor(ren, col.r, col.g, col.b, 0xFF);
	SDL_RenderDrawPoint(ren, x, y);
}
