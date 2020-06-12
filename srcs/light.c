/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:36:57 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/12 14:51:47 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_or_shadow(t_rtv *r, t_light light, float dist_max,
						float *intensity)
{
	t_vec3	p_to_light;
	float	dist_p_to_light;
	float	dist_p_to_obj;

	trace_zero(&r->trace);
	r->trace.from = (t_vec3)r->ray.p;
	r->trace.to = (t_vec3)light.direction;
	if (r->closest.type == TYPE_CONE)
		r->trace.dist_min = 1.0f;
	else
		r->trace.dist_min = 0.001f;
	r->trace.dist_max = dist_max;
	p_to_light = vec_diff(r->ray.p, light.position);
	dist_p_to_light = sqrtf(dot_product(p_to_light, p_to_light));
	dist_p_to_obj = trace_p_to_light(r);
	if (dist_p_to_obj == -1.0f)
		calculate_types_light(r, light, r->closest.mat, intensity);
	else if (dist_p_to_light < dist_p_to_obj)
		calculate_types_light(r, light, r->closest.mat, intensity);
}

void	current_type_light(t_light *current, t_rtv *r, float *intensity)
{
	float	dist_max;

	dist_max = 0.0f;
	if (current->type == LIGHT_TYPE_POINT)
	{
		current->direction = vec_diff(current->position, r->ray.p);
		dist_max = 1;
	}
	if (current->type == LIGHT_TYPE_DIRECTIONAL)
	{
		current->position = vec_diff(r->ray.p, current->direction);
		dist_max = FLT_MAX;
	}
	if (current->type == LIGHT_TYPE_AMBIENT)
		*intensity += current->intensity;
	else
		light_or_shadow(r, *current, dist_max, intensity);
}

void	iterate_light(t_rtv *r, float *intensity)
{
	t_light *current;

	current = r->light;
	while (current != NULL)
	{
		current_type_light(current, r, intensity);
		current = current->next;
	}
	if (*intensity >= 1.0f)
		*intensity = 1.0f;
}

t_color	calculate_lightning(t_rtv *r, t_close_obj closest)
{
	float	intensity;
	t_color	col;

	col = (t_color){0.0f, 0.0f, 0.0f};
	intensity = 0.0f;
	r->ray.reverse_dir = mult_vec_const(r->ray.dir, -1);
	r->ray.p = vec_add(r->camera, mult_vec_const(r->ray.dir, closest.dist));
	normal(closest, r);
	iterate_light(r, &intensity);
	add_light(closest.mat.color, &col, intensity);
	return (col);
}

void	add_light(t_color col, t_color *res_col, float intensity)
{
	res_col->r = col.r * intensity;
	res_col->g = col.g * intensity;
	res_col->b = col.b * intensity;
}