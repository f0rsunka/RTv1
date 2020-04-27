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

typedef struct 		s_material
{
	t_vec2			a;
	t_color			color;
	float			specular;
}					t_material;

typedef struct		s_sphere
{
	t_vec3			center;
	float			radius;
	t_material		material;
}					t_sphere;

typedef struct		s_closest_obj
{
	void			*obj;
	float			dist;
}					t_closest_obj;

// typedef struct		s_intersect
// {
// 	t_closest_sphere s;
// 	t_vec3			p;
// 	t_vec3			normal;
// 	t_material		material;
// }					t_intersect;

// typedef struct	s_primitive
// {

// }				t_primitive;



// typedef struct		s_viewport
// {
// 	int				w;
// 	int				h;
// 	int				d;
// }					t_viewport;

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

typedef struct 		s_scene
{
	void			*object;
	// size_t			size;
	int				type;
	struct s_scene	*next;
}					t_scene;


typedef struct		s_coefficients
{
	float			a;
	float			b;
	float			c;
}					t_coefficients;

typedef struct		s_place
{

}					t_place;

typedef struct		s_cone
{

}					t_cone;

typedef struct		s_cylinder
{
	
}					t_cylinder;

typedef struct		s_ray
{
	t_vec3			dir;
	t_vec3			reverse_dir;
	t_vec3			p;
	t_vec3			normal;
}					t_ray;

typedef struct 		s_rtv
{
	t_sdl			sdl;
	t_vec3			camera;
	t_ray			ray;
	t_scene			*scene;
	// t_viewport		viewport;
	t_light			*light;
	int				count_lights;
}					t_rtv;

#endif