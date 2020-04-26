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
t_sphere	*init_sphere(t_rtv *r);
t_light		*init_light(t_rtv *r);

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

void		choice_sphere(int i, t_scene *scene);
int 		intersect_ray_sphere(t_vec3 camera, t_vec3 dir, t_sphere sphere, float *sphere_dist);
float		get_light(t_closest_sphere closest, t_vec3 dir, t_rtv *r);

/*
** *********************************** **
** *********************************** **
**              rendering     		   **
** *********************************** **
** *********************************** **
*/

void		render(t_rtv *rtv);
t_color		trace_ray(t_vec3 camera, t_vec3 dir, t_rtv *r);


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

float		get_light(t_closest_sphere closest, t_vec3 dir, t_rtv *r);
t_color		add_light(t_color col, t_closest_sphere closest, t_vec3 dir, t_rtv *r);
float		calculate_lightning(t_rtv *r, t_vec3 dir, t_intersect intersect, t_vec3 p);
float		calculate_diffuse(float light_intensity, t_vec3 light_dir, t_vec3 normal_dir);
float		calculate_reflection(t_vec3 view, t_vec3 light_dir, float light_intensity, t_intersect intersect);

/*
** *********************************** **
** *********************************** **
**               color       		   **
** *********************************** **
** *********************************** **
*/

int			get_color(t_color color);
t_color		transform_color(t_color col);
// float		transform_float(float digit);
float		transform_specular(float s);

#endif
