/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:10:56 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 22:23:13 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
#include "rtv1.h"
#include "structs.h"

void		rtv_test(t_rtv *rtv, t_sphere *mas_sphere);
void		create_mas_sphere(t_rtv *r);
t_color		trace_ray(t_vector3d camera, t_vector3d *D, double t_min, t_sphere *sphere);
t_vector3d 	*vec_diff(t_vector3d *v1, t_vector3d *v2);
double		dot_product(t_vector3d *v1, t_vector3d *v2);
// t_sphere *new_sphere(t_vector3d center, double radius, t_color color);
t_mlx		init_mlx(void);

int		key_press(int k, t_rtv *r);
int		close_hook(void *param);

void		check_hooks_loops(t_rtv *r);
int		get_color(t_color color);

#endif