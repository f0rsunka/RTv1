/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:56 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/05 22:00:46 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
#include "rtv1.h"
#include "structs.h"

/** *********************************** **/
/** *********************************** **/
/**            func for mlx             **/
/** *********************************** **/
/** *********************************** **/

t_mlx		init_mlx(void);
int			key_press(int k, t_rtv *r);
int			close_hook(void *param);
void		check_hooks_loops(t_rtv *r);
int			draw_all_hook(t_rtv *r);

/** *********************************** **/
/** *********************************** **/
/**               sphere       			**/
/** *********************************** **/
/** *********************************** **/

void		rtv_test(t_rtv *rtv);
void		create_spheres(t_rtv *r);
t_color		trace_ray(t_vec3 camera, t_vec3 D, double t_min, t_rtv *r);

/** *********************************** **/
/** *********************************** **/
/**               color       			**/
/** *********************************** **/
/** *********************************** **/

int			get_color(t_color color);

/** *********************************** **/
/** *********************************** **/
/**            func for vectors         **/
/** *********************************** **/
/** *********************************** **/

t_vec3 		vec_diff(t_vec3 v1, t_vec3 v2);
double		dot_product(t_vec3 v1, t_vec3 v2);

/** *********************************** **/
/** *********************************** **/
/**               init_rtv     			**/
/** *********************************** **/
/** *********************************** **/

t_vec3		init_camera(void);
t_viewport	init_viewport(void);

/** *********************************** **/
/** *********************************** **/
/**         primary rendering     		**/
/** *********************************** **/
/** *********************************** **/

void	draw_background(t_rtv *rtv);

#endif
