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

float	calculate_diffuse(float light_intensity, t_vec3 light_dir, t_vec3 normal_dir, float *dot)
{
	float len_l;
	float len_n;
	float intensity;

	*dot = dot_product(light_dir, normal_dir);
	if (*dot <= 0)
		return (0.0f);
	len_l = vec_length(light_dir);
	len_n = vec_length(normal_dir);
	intensity = light_intensity * (*dot / (len_l * len_n));
	return (intensity);
}

float	calculate_reflection(t_vec3 view, t_vec3 light_dir, t_vec3 normal_dir, float light_intensity, float s, float *dot_l_n)
{
	t_vec3	reflection;
	float	dot_r_v;
	float	len_r;
	float	len_v;
	float	intensity;
	float	x;

	reflection = vec_diff(light_dir, vec_add_const(vec_add_const(normal_dir, 2.0f), *dot_l_n));
	dot_r_v = dot_product(reflection, view);
	if (dot_r_v <= 0)
		return (0.0f);
	len_r = vec_length(reflection);
	len_v = vec_length(view);
	x = (dot_r_v / (len_r * len_v));
	intensity = light_intensity * pow(x, s);
	return (intensity);
}

float	calculate_intensity(float light_intensity, t_vec3 light_dir, t_vec3 normal_dir, float s, t_vec3 view)
{
	float intensity;
	float dot_l_n;

	intensity = 0.0f;
	intensity += calculate_diffuse(light_intensity, light_dir, normal_dir, &dot_l_n);
	if (s >= 0)
		intensity += calculate_reflection(view, light_dir, normal_dir, light_intensity, s, &dot_l_n);
	return (intensity);
}

float	calculate_lightning(t_rtv *r, t_vec3 dir, t_vec3 normal_dir, float s)
{
	int		i;
	float	total_intensity;
	t_vec3	light_dir;

	i = 0;
	total_intensity = 0.0f;
	while (i < r->count_lights)
	{
		if (!ft_strcmp(r->light[i].type, POINT))
			light_dir = vec_diff(r->light[i].position, dir);
		if (!ft_strcmp(r->light[i].type, DIRECTIONAL))
			light_dir = r->light[i].direction;
		if (!ft_strcmp(r->light[i].type, AMBIENT))
			total_intensity += r->light[i].intensity;
		else
			total_intensity += calculate_intensity(r->light[i].intensity, light_dir, normal_dir, s, vec_add_const(dir, -1));
		i++;
	}
	return (total_intensity);
}

t_color	add_light(t_color col, float intensity)
{
	col.r *= intensity;
	col.g *= intensity;
	col.b *= intensity;
	return (col);
}
