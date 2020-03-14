/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/14 18:24:38 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
#include "rtv1.h"

typedef struct 		s_vec3
{	
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct 		s_ivec3
{	
	int				x;
	int				y;
	int				z;
}					t_ivec3;

typedef struct		s_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct		s_ivec2
{
	int				x;
	int				y;
}					t_ivec2;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_sphere
{
	t_vec3			center;
	double			radius;
	t_color			color;
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

typedef struct		s_viewport
{
	int				w;
	int				h;
	int				d;
}					t_viewport;

typedef struct		s_light
{
	t_vec3			position;
	float			intensity;
}					t_light;

typedef struct		s_mlx
{
	void			*mptr;
	void			*wptr;
	void			*iptr;
	int				*img;
}					t_mlx;

typedef struct 		s_rtv
{
	t_mlx			mlx;
	t_vec3			camera;
	t_viewport		viewport;
	t_vec3			point_in_3d;
	t_sphere		**sphere;
	int				count_objects;
	t_light			light;
	int				count_lights;
}					t_rtv;

#endif