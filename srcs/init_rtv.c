/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rtv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:02:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/10 18:53:07 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_camera(t_rtv *r)
{
	r->camera = (t_vec3){0.0f, 0.0f, 0.0f};
}

void	init_flags(t_flag *flag)
{
	flag->is_move = 0;
	flag->is_rotate = 0;
}

void	ray_zero(t_ray *ray)
{
	ray->dir = (t_vec3){0.0f, 0.0f, 0.0f};
	ray->normal = (t_vec3){0.0f, 0.0f, 0.0f};
	ray->p = (t_vec3){0.0f, 0.0f, 0.0f};
	ray->reverse_dir = (t_vec3){0.0f, 0.0f, 0.0f};
}

void	trace_zero(t_trace *trace)
{
	trace->from = (t_vec3){0.0f, 0.0f, 0.0f};
	trace->to = (t_vec3){0.0f, 0.0f, 0.0f};
	trace->dist_min = 0.0f;
	trace->dist_max = 0.0f;
}

void	closest_zero(t_close_obj *cl)
{
	cl->obj = NULL;
	cl->type = 0;
	cl->dist = FLT_MAX;
	cl->mat.color = (t_color){0.0f, 0.0f, 0.0f};
	cl->mat.specular = 0.0f;
	cl->color = (t_color){0.0f, 0.0f, 0.0f};
}
