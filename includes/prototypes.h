/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:56 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/09 17:17:23 by f0rsunka         ###   ########.fr       */
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

void		init_flags(t_flag *flag);
void		init_camera(t_rtv *r);
void		ray_zero(t_ray *ray);
void		trace_zero(t_trace *trace);
void		closest_zero(t_close_obj *cl);

/*
** *********************************** **
** *********************************** **
**              rendering     		   **
** *********************************** **
** *********************************** **
*/

void		render(t_rtv *rtv);
t_close_obj	trace_ray(t_rtv *r);
int			sphere_intersect(t_rtv *r, t_scene *current, t_close_obj *close);
int			cylinder_intersect(t_rtv *r, t_scene *current, t_close_obj *close);
int			plane_intersect(t_rtv *r, t_scene *current, t_close_obj *closest);
int			cone_intersect(t_rtv *r, t_scene *current, t_close_obj *closest);
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

float		calc_discriminant(float a, float b, float c);
void		sphere_calc_coefficients(t_coefficients *c, t_vec3 ofs, t_vec3 dir, float r);
void		cylinder_calc_coefficients(t_coefficients *c, t_vec3 ofs, t_vec3 dir, t_cylinder cylinder);
void		cone_calc_coefficients(t_coefficients *c, t_vec3 ofs, t_vec3 dir, t_cone cone);
int			is_sqrt_valide(float t1, float t2, float *dist);
/*
** *********************************** **
** *********************************** **
**              lightning     		   **
** *********************************** **
** *********************************** **
*/

t_color 	calculate_lightning(t_rtv *r, t_close_obj closest);
void		normal(t_close_obj closest, t_rtv *r);
void		calculate_diffuse(t_light light, t_vec3 normal, float *intensity);
void		calculate_specular(t_rtv *r, t_light light, float specular, float *intensity);
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

float		trace_p_to_light(t_rtv *r);

/*
** *********************************** **
** *********************************** **
**               move       		   **
** *******************************
 * *** **
** *********************************** **
*/

void		rotate(t_vec3 *vec, t_vec3 angle);
void		events(t_rtv *r);

/*
** *********************************** **
** *********************************** **
**               parser       		   **
** *********************************** **
** *********************************** **
*/

void        read_scene(t_rtv *r, char *filename);

/*
** *********************************** **
** *********************************** **
**               errors       		   **
** *********************************** **
** *********************************** **
*/

void		rtv_error(int n);
void		arguments_errors(int n);
void		window_errors(int n);
void		malloc_error(int n);
void		lights_errors(int n);
void		primitives_errors(int n);
void		write_error(char *reason);

/*
** *********************************** **
** *********************************** **
**            check value     		   **
** *********************************** **
** *********************************** **
*/

void		check_coefficients_cyl(t_vec3 coef);
void		check_radius(float r);
void		check_specular(float s);
void		check_coefficients_cone(t_vec3 coef);

#endif
