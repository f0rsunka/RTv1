/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:36:57 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/05 12:48:32 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	calculate_types_light(t_rtv *r, t_light light, t_material material, float *intensity)
{
	calculate_diffuse(light, r->ray.normal, intensity);
	if (material.specular >= 0)
		calculate_specular(r->ray, light, material.specular, intensity);
}

// if (is_shadow(r) == 1) - если найден объекты

void	iterate_light(t_rtv *r, t_material material, float *intensity)
{
	int		i;
	t_vec3	light_dir;

	i = 0;
	while (i < COUNT_LIGHTS)
	{
		if (!ft_strcmp(r->light[i].type, POINT))
		{
			r->light[i].direction = vec_diff(r->ray.p, r->light[i].position);
		}
		if (!ft_strcmp(r->light[i].type, DIRECTIONAL))
		{
			r->light[i].position = vec_diff(r->ray.p, r->light[i].direction);
		}
		if (!ft_strcmp(r->light[i].type, AMBIENT))
		{
			*intensity += r->light[i].intensity;
		}
		else
		{
			light_dir = r->light[i].direction;
			light_dir = mult_vec_const(r->light[i].direction, -1);
			trace_zero(&r->trace);
			r->trace = (t_trace){(t_vec3)r->ray.p, (t_vec3)light_dir, (float)0.001f, DIST_MAX};
			// if (is_shadow(r).obj == 0)
			// 	calculate_types_light(r, r->light[i], material, intensity);
		
			t_vec3 p_to_light;
			float dist_p_to_light;
			float dist_p_to_obj;
			p_to_light = vec_diff(r->ray.p, r->light[i].position);
			dist_p_to_light = sqrtf(dot_product(p_to_light, p_to_light));
			dist_p_to_obj = is_shadow(r);
			if (dist_p_to_obj == -1.0f)
				calculate_types_light(r, r->light[i], material, intensity);
			else if (dist_p_to_light < dist_p_to_obj)
					calculate_types_light(r, r->light[i], material, intensity);
		}
		i++;
	}
	if (*intensity > 1.0f)
		*intensity = 1.0f;
}

void	init_point(t_closest_obj cl, t_vec3 camera, t_rtv *r)
{
	if (cl.type == SPHERE)
		r->ray.p = vec_add(camera, mult_vec_const(r->ray.dir, cl.dist));
	if (cl.type == CYLINDER)
		r->ray.p = vec_add(camera, mult_vec_const(r->ray.dir, cl.dist));
	if (cl.type == PLANE)
		r->ray.p = vec_add(camera, mult_vec_const(r->ray.dir, cl.dist));
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
	iterate_light(r, closest.mat, &intensity);
	add_light(closest.mat.color, &col, intensity);
	return (col);
}

void	add_light(t_color col, t_color *res_col, float intensity)
{
	res_col->r = col.r * intensity;
	res_col->g = col.g * intensity;
	res_col->b = col.b * intensity;
}
