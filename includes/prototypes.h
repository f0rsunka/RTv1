/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:56 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 18:57:41 by cvernius         ###   ########.fr       */
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
**               init rtv     		   **
** *********************************** **
** *********************************** **
*/

t_vec3		init_camera(void);
// t_viewport	init_viewport(void);
t_light		*init_light(void);

/*
** *********************************** **
** *********************************** **
**           init primitive      	   **
** *********************************** **
** *********************************** **
*/

void		init_primitive(t_rtv *r);

/*
** *********************************** **
** *********************************** **
**               sphere       		   **
** *********************************** **
** *********************************** **
*/

void		init_sphere(int i, t_scene *scene);
int 		intersect_ray_sphere(t_vec3 camera, t_vec3 dir, t_sphere sphere, float *sphere_dist);

/*
** *********************************** **
** *********************************** **
**              rendering     		   **
** *********************************** **
** *********************************** **
*/

void		render(t_rtv *rtv);
t_collision	trace_ray(t_rtv *r, int depth);
// t_color		trace_ray(t_rtv *r);
void 		init_trace(t_trace *trace, t_vec3 from, t_vec3 to, float dist_min);
void		trace_zero(t_rtv *r);
int			sphere_intersect(t_rtv *r, t_scene *current, t_closest_obj *closest);

/*
** *********************************** **
** *********************************** **
**          quadratic_equation         **
** *********************************** **
** *********************************** **
*/

float		calculate_quadratic_equation(t_vec3 length_cam_center, t_vec3 dir, float r, float *t1, float *t2);
float		calc_discriminant(float a, float b, float c);
float		calc_a(t_vec3 dir);
float		calc_b(t_vec3 length_cam_center, t_vec3 dir);
float		calc_c(t_vec3 length_cam_center, float r);

/*
** *********************************** **
** *********************************** **
**              lightning     		   **
** *********************************** **
** *********************************** **
*/

t_color 	calculate_lightning(t_rtv *r, t_closest_obj closest);
t_vec3		get_normal_sphere(t_vec3 p, t_vec3 center_sphere);
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
int			compare_color(t_color c1, t_color c2);
t_color		calculate_reflected_color(t_color col, float r, t_color refl_col);

/*
** *********************************** **
** *********************************** **
**               shadow       		   **
** *********************************** **
** *********************************** **
*/

int			is_shadow(t_rtv *r);
// t_collision		is_shadow(t_rtv *r);

#endif
