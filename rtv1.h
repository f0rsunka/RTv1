/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:02:59 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/28 16:46:22 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <SDL/SDL.h>
#ifndef RTV1_H
# define RTV1_H
#include <stdlib.h>
#include <SDL.h>
# define WIDTH 1800
# define HEIGHT 1000
// # define BACKGROUND_COLOR 255
// # define d 1
# define t_max 100000

typedef struct 	s_vector3d
{
	double		x;
	double		y;
	double		z;
}				t_vector3d;

typedef struct	s_vector2d
{
	double		x;
	double		y;
}				t_vector2d;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_sphere
{
	t_vector3d	center;
	double		radius;
	t_color		color;
}				t_sphere;

// typedef struct	s_primitive
// {

// }				t_primitive;

typedef struct	s_viewport
{
	int			w;
	int			h;
	double		d; //?? mb int
}				t_viewport;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}					t_sdl;

#endif
