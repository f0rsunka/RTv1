/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:02:59 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/05 19:49:08 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <../SDL2_libs/SDL2.framework/Headers/SDL.h>
#ifndef RTV1_H
# define RTV1_H
// #include <SDL.h>
#include "../MinilibX/mlx.h"
#include <stdlib.h>
#include <stdio.h> //!---------------------------------------------------------
// #include "libft/libft.h"
# define WIN_W 1800
# define WIN_H 1000
// # define BACKGROUND_COLOR 255
// # define d 1
# define t_max 100000.0

typedef struct 	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_sphere
{
	t_vec3	center;
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

typedef struct		s_mlx
{
	void			*mptr;
	void			*wptr;
	void			*iptr;
	int				*img;
}					t_mlx;

// typedef struct		s_sdl
// {
// 	SDL_Window		*window;
// 	SDL_Renderer	*renderer;
// 	SDL_Event		event;
// }					t_sdl;

void		rtv_test(t_sdl *sdl, t_sphere *mas_sphere);
t_color		trace_ray(t_vec3 camera, t_vec3 *D, double t_min, t_sphere *sphere);
t_vec3 	*vec_diff(t_vec3 *v1, t_vec3 *v2);
double		dot_product(t_vec3 *v1, t_vec3 *v2);
t_sphere	new_sphere(t_vec3 center, double radius, t_color color);
void		init_sdl(t_sdl *sdl);
void		destroy_sdl(t_sdl *sdl);
void		clear_window_sdl(t_sdl *sdl);

#endif
