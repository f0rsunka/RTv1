/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:56 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 16:33:45 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
#include "rtv1.h"
#include "structs.h"

/*
** *********************************** **
** *********************************** **
**                 mlx                 **
** *********************************** **
** *********************************** **
*/

t_mlx		init_mlx(void);
int			key_press(int k, t_rtv *r);
int			close_hook(void *param);
void		check_hooks_loops(t_rtv *r);
int			draw_all_hook(t_rtv *r);

/*
** *********************************** **
** *********************************** **
**               sphere       		   **
** *********************************** **
** *********************************** **
*/

void		render_sphere(t_rtv *rtv);
void		init_spheres(t_rtv *r);
int 		intersect_ray_sphere(t_vec3 camera, t_vec3 point_3d, t_sphere *sphere, float *dist_to_sphere);
t_color		cast_ray(t_vec3 camera, t_vec3 dir, t_rtv *r);

/*
** *********************************** **
** *********************************** **
**               color       		   **
** *********************************** **
** *********************************** **
*/

int			get_color(t_color color);

/*
** *********************************** **
** *********************************** **
**          quadratic_equation         **
** *********************************** **
** *********************************** **
*/

float		calculate_quadratic_equation(t_vec3 length_cam_center, t_vec3 dir, float r, float *t1, float *t2);
float		calc_discriminant(float a, float b, float c);
float		calc_b(t_vec3 length_cam_center, t_vec3 dir);
float		calc_a(t_vec3 dir);
float		calc_c(t_vec3 length_cam_center, float r);

/*
** *********************************** **
** *********************************** **
**               init_rtv     		   **
** *********************************** **
** *********************************** **
*/

t_vec3		init_camera(void);
t_viewport	init_viewport(void);
t_light		init_light(void);

/*
** *********************************** **
** *********************************** **
**              lightning     		   **
** *********************************** **
** *********************************** **
*/

float	calculate_lightning(t_rtv *r, t_vec3 dir, t_vec3 vec_n);
t_color	color_with_light(t_color col, float count_lights);

#endif
