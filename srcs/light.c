/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:36:57 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 15:35:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	calculate_types_light(t_rtv *r, t_light *light, t_material material, float *intensity)
{
	calculate_diffuse(light, r->ray.normal, intensity);
	if (material.specular >= 0)
		calculate_specular(r->ray, light, material.specular, intensity);
}

void	iterate_light(t_rtv *r, t_material material, int type, float *intensity)
{
	int		i;
	t_vec3	light_dir;
	t_light	*cur;

	cur = r->light;
	while (cur)
	{
		if (cur->type == LIGHT_TYPE_HEAD) {
			cur = cur->next;
			continue;
		}
		if (cur->type == LIGHT_TYPE_POINT)
		{
			cur->direction = vec_diff(r->ray.p, cur->position);
		}
		if (cur->type == LIGHT_TYPE_DIRECTIONAL)
		{
			cur->direction = cur->direction;
		}
		if (cur->type == LIGHT_TYPE_AMBIENT)
		{
			*intensity += cur->intensity;
		}
		else
		{
			light_dir = mult_vec_const(cur->direction, -1);
			trace_zero(r);
			r->trace = (t_trace){(t_vec3)r->ray.p, (t_vec3)light_dir, (float)0.001f};
			if (is_shadow(r) == 0)
				calculate_types_light(r, cur, material, intensity);
		}
		cur = cur->next;
	}
	if (*intensity > 1.0f)
		*intensity = 1.0f;
}

void	init_point(t_closest_obj cl, t_vec3 camera, t_rtv *r)
{
	if (cl.type == SPHERE)
		r->ray.p = vec_add(camera, mult_vec_const(r->ray.reverse_dir, cl.dist));
	if (cl.type == CYLINDER)
		r->ray.p = vec_add(mult_vec_const(camera, -1), mult_vec_const(r->ray.dir, cl.dist));
}

t_color calculate_lightning(t_rtv *r, t_closest_obj closest)
{
	float	intensity;
	t_color	col;

	col = (t_color){0.0f, 0.0f, 0.0f};
	intensity = 0.0f;
	r->ray.reverse_dir = mult_vec_const(r->ray.dir, -1);
	init_point(closest, r->camera, r);
	normal(closest, r);
	iterate_light(r, closest.mat, closest.type, &intensity);
	add_light(closest.mat.color, &col, intensity);
	return (col);
}

void	add_light(t_color col, t_color *res_col, float intensity)
{
	res_col->r = col.r * intensity;
	res_col->g = col.g * intensity;
	res_col->b = col.b * intensity;
}
