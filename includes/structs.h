/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 19:15:50 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
#include "rtv1.h"

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;

typedef struct		s_sphere
{
	t_vec3			center;
	float			radius;
	t_color			color;
	float			specular;
}					t_sphere;

typedef struct		s_coefficients
{
	float			a;
	float			b;
	float			c;
}					t_coefficients;

// typedef struct		s_intersect_sphere
// {
// 	t_vec3 			length_cam_center;
// 	t_vec3			dir;
// 	float			radius;
// 	t_coefficients	c;
// 	float			d;
// 	float			t1;
// 	float			t2;
// }					t_intersect_sphere;

// typedef struct	s_primitive
// {

// }				t_primitive;

typedef struct		s_closest_sphere
{
	t_sphere		*sphere;
	float			dist;
}					t_closest_sphere;

typedef struct		s_viewport
{
	int				w;
	int				h;
	int				d;
}					t_viewport;

typedef struct		s_light
{
	char			*type;
	float			intensity;
	t_vec3			position;
	t_vec3			direction;
}					t_light;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}					t_sdl;

typedef struct 		s_rtv
{
	t_sdl			sdl;
	t_vec3			camera;
	t_viewport		viewport;
	t_vec3			point_in_3d;
	t_sphere		*sphere;
	int				count_objects;
	t_light			*light;
	int				count_lights;
}					t_rtv;

#endif