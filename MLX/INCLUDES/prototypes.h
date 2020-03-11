/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:56 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/11 20:17:43 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
#include "rtv1.h"
#include "structs.h"

/*
** *********************************** **
** *********************************** **
**            func for mlx             **
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
// t_color		trace_ray(t_vec3 camera, t_vec3 D, double t_min, t_rtv *r);
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
**            vector_operations        **
** *********************************** **
** *********************************** **
*/

t_vec3 		vec_diff(t_vec3 v1, t_vec3 v2);
double		dot_product(t_vec3 v1, t_vec3 v2);
t_vec3 		vec_add(t_vec3 v1, t_vec3 v2);
t_vec3		vec_normalize(t_vec3 v);
t_vec3		vec_add_const(t_vec3 v, float n);

/*
** *********************************** **
** *********************************** **
**               init_rtv     		   **
** *********************************** **
** *********************************** **
*/

t_vec3		init_camera(void);
t_viewport	init_viewport(void);

/*
** *********************************** **
** *********************************** **
**         primary rendering     	   **
** *********************************** **
** *********************************** **
*/

void	draw_background(t_rtv *rtv);

#endif
