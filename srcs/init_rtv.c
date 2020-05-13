/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rtv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:02:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 15:26:21 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_camera(t_rtv *r)
{
	r->camera = (t_vec3){0.0f, 0.0f, 0.0f};
}

void	init_flags(t_rtv *r)
{
	r->flag.is_move = 0;
	r->flag.is_rotate = 0;
}

void	ray_zero(t_ray *ray)
{
	ray->dir = (t_vec3){0.0f, 0.0f, 0.0f};
	ray->normal = (t_vec3){0.0f, 0.0f, 0.0f};
	ray->p = (t_vec3){0.0f, 0.0f, 0.0f};
	ray->reverse_dir = (t_vec3){0.0f, 0.0f, 0.0f};
	ray->angle = (t_vec3){0.0f, 0.0f, 0.0f};
}

void	trace_zero(t_rtv *r)
{
	r->trace.from = (t_vec3){0.0f, 0.0f, 0.0f};
	r->trace.to = (t_vec3){0.0f, 0.0f, 0.0f};
	r->trace.dist_min = 0.0f;
}

// t_viewport	init_viewport(void)
// {
// 	t_viewport viewport;

// 	viewport = (t_viewport){1, 1, 1};
// 	return (viewport);
// }
