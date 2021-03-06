/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/12 15:07:53 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "rtv1.h"

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;

typedef struct		s_material
{
	t_color			color;
	float			specular;
}					t_material;

typedef struct		s_light
{
	int				type;
	float			intensity;
	t_vec3			position;
	t_vec3			direction;
	struct s_light	*next;
}					t_light;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_coefficients
{
	float			a;
	float			b;
	float			c;
}					t_coefficients;

typedef struct		s_ray
{
	t_vec3			dir;
	t_vec3			reverse_dir;
	t_vec3			p;
	t_vec3			normal;
	t_vec3			angle;
	t_vec3			ofs;
}					t_ray;

typedef struct		s_scene
{
	void			*object;
	int				type;
	struct s_scene	*next;
}					t_scene;

typedef struct		s_trace
{
	t_vec3			from;
	t_vec3			to;
	float			dist_min;
	float			dist_max;
}					t_trace;

typedef struct		s_flag
{
	int				is_move;
	int				is_rotate;
}					t_flag;

typedef struct		s_close_obj
{
	void			*obj;
	int				type;
	float			dist;
	t_vec3			normal;
	t_material		mat;
	t_color			color;
}					t_close_obj;

typedef struct		s_sphere
{
	t_vec3			center;
	float			radius;
	t_vec3			angle;
	t_material		material;
}					t_sphere;

typedef struct		s_plane
{
	t_vec3			offset;
	t_vec3			coef;
	t_vec3			normal;
	t_vec3			angle;
	t_material		material;
}					t_plane;

typedef struct		s_cone
{
	t_vec3			offset;
	t_vec3			coef;
	t_vec3			normal;
	t_vec3			angle;
	t_material		material;
}					t_cone;

typedef struct		s_cylinder
{
	float			radius;
	t_vec3			offset;
	t_vec3			coef;
	t_vec3			normal;
	t_vec3			angle;
	t_material		material;
}					t_cylinder;

typedef struct		s_rtv
{
	t_sdl			sdl;
	t_vec3			camera;
	t_trace			trace;
	t_close_obj		closest;
	t_ray			ray;
	t_scene			*scene;
	t_light			*light;
	t_flag			flag;
}					t_rtv;

#endif
