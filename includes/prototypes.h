/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:56 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/04 18:06:54 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
#include "rtv1.h"
#include "structs.h"

/*
** *********************************** **
** *********************************** **
**                 sdl       		   **
** *********************************** **
** *********************************** **
*/

t_sdl		init_sdl(void);
void		destroy_sdl(t_sdl sdl);
void		clear_window_sdl(t_sdl sdl);
void		put_pixel(SDL_Renderer *ren, int x, int y, t_color col);

/*
** *********************************** **
** *********************************** **
**          init everything       	   **
** *********************************** **
** *********************************** **
*/

void		init_primitives(t_rtv *r);
void		init_sphere(int i, t_scene *scene);
void		init_flags(t_flag *flag);
void		init_camera(t_rtv *r);
void		ray_zero(t_ray *ray);
void		trace_zero(t_trace *trace);
void		closest_zero(t_closest_obj *cl);

/*
** *********************************** **
** *********************************** **
**              rendering     		   **
** *********************************** **
** *********************************** **
*/

void		render(t_rtv *rtv);
t_closest_obj	trace_ray(t_rtv *r);
int			sphere_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest);
int			cylinder_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest);
int			plane_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest);
int 		is_sphere(t_vec3 camera, t_vec3 dir, t_sphere sphere, float *sphere_dist);
int 		is_cylinder(t_vec3 camera, t_vec3 dir, t_cylinder cylinder, float *cylinder_dist);
int 		is_plane(t_vec3 camera, t_vec3 dir, t_plane plane, float *plane_dist);
int			is_cone(t_vec3 camera, t_vec3 dir, t_cone cone, float *cone_dist);

/*
** *********************************** **
** *********************************** **
**          quadratic_equation         **
** *********************************** **
** *********************************** **
*/

float		quadratic_equation(t_vec3 ofs, t_vec3 dir, float r, float *t1, float *t2);
float		calc_discriminant(float a, float b, float c);
float		calc_a(t_vec3 dir);
float		calc_b(t_vec3 ofs, t_vec3 dir);
float		calc_c(t_vec3 ofs, float r);

/*
** *********************************** **
** *********************************** **
**              lightning     		   **
** *********************************** **
** *********************************** **
*/

t_light		*init_light(void);
t_color 	calculate_lightning(t_rtv *r, t_closest_obj closest);
void		normal(t_closest_obj closest, t_rtv *r);
void		calculate_diffuse(t_light light, t_vec3 normal, float *intensity);
void		calculate_specular(t_ray ray, t_light light, float specular, float *intensity);
void		add_light(t_color col, t_color *res_col, float intensity);

/*
** *********************************** **
** *********************************** **
**               color       		   **
** *********************************** **
** *********************************** **
*/

int			get_color(t_color color);
t_color		float_to_byte(t_color col);
t_color		byte_to_float(t_color col);

/*
** *********************************** **
** *********************************** **
**               shadow       		   **
** *********************************** **
** *********************************** **
*/

t_closest_obj			is_shadow(t_rtv *r);

/*
** *********************************** **
** *********************************** **
**               move       		   **
** *********************************** **
** *********************************** **
*/

void		rotate(t_ray *ray);
void		events(t_rtv *r);

#endif
