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

float	calculate_diffuse(float light_intensity, t_vec3 light_dir, t_vec3 normal_dir)
{
	float dot_l_n;
	float len_l;
	float len_n;
	float intensity;

	dot_l_n = dot_product(light_dir, normal_dir);
	if (dot_l_n <= 0)
	{
		// printf("i'm lox\n");
		return (0.0f);
	}
	// printf("dot = %f\n", dot_l_n);
	len_l = vec_length(light_dir);
	len_n = vec_length(normal_dir);
	intensity = light_intensity * (dot_l_n / (len_l * len_n));
	// printf("intensity = %f\n", intensity);
	return (intensity);
}

float	calculate_reflection(t_vec3 view, t_vec3 light_dir, t_vec3 normal_dir, float light_intensity, float s)
{
	t_vec3	reflection;
	float	dot_l_n;
	float	dot_r_v;
	float	len_r;
	float	len_v;
	float	intensity;
	float	x;

	dot_l_n = dot_product(light_dir, normal_dir);
	reflection = vec_diff(light_dir, vec_add_const(vec_add_const(normal_dir, 2.0f), dot_l_n));
	dot_r_v = dot_product(reflection, view);
	if (dot_r_v <= 0)
		return (0.0f);
	len_r = vec_length(reflection);
	len_v = vec_length(view);
	x = (dot_r_v / (len_r * len_v));
	intensity = light_intensity * powf(x, s);
	return (intensity);
}

float	calculate_intensity(float light_intensity, t_vec3 light_dir, t_vec3 normal_dir, float s, t_vec3 view)
{
	float intensity;

	intensity = 0.0f;
	intensity += calculate_diffuse(light_intensity, light_dir, normal_dir);
	// if (s >= 0)
	// 	intensity += calculate_reflection(view, light_dir, normal_dir, light_intensity, s);
	// printf("intensity = %f\n", intensity);
	return (intensity);
}

float	calculate_lightning(t_rtv *r, t_vec3 dir, t_vec3 normal_dir, float s, t_vec3 p)
{
	int		i;
	float	total_intensity;
	t_vec3	light_dir;

	i = 0;
	total_intensity = 0.0f;
	while (i < r->count_lights)
	{
		if (!ft_strcmp(r->light[i].type, POINT))
			light_dir = vec_diff(p, r->light[i].position);
		if (!ft_strcmp(r->light[i].type, DIRECTIONAL))
			light_dir = r->light[i].direction;
		if (!ft_strcmp(r->light[i].type, AMBIENT))
			total_intensity += r->light[i].intensity;
		else
			total_intensity += calculate_intensity(r->light[i].intensity, light_dir, normal_dir, s, dir);
		i++;
	}
	if (total_intensity > 1.0f)
		total_intensity = 1.0f;
	// if (total_intensity != 0.2f)
		// printf("total === %f\n", total_intensity);
	return (total_intensity);
}

t_color	add_light(t_color col, float intensity)
{
	col.r *= intensity;
	col.g *= intensity;
	col.b *= intensity;
	return (col);
}
