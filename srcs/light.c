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

float	calculate_total_intensity(float light_intensity, t_vec3 light_dir, t_vec3 normal_dir)
{
	float dot;
	float length_l;
	float length_n;
	float intensity;

	dot = dot_product(light_dir, normal_dir);
	if (dot <= 0)
		return (0.0f);
	length_l = vec_length(light_dir);
	length_n = vec_length(normal_dir);
	intensity = light_intensity * (dot / (length_l * length_n));
	return (intensity);
}

float	calculate_lightning(t_rtv *r, t_vec3 point_dir, t_vec3 normal_dir)
{
	int		i;
	float	total_intensity;
	t_vec3	light_dir;

	i = 0;
	total_intensity = 0.0f;
	while (i < r->count_lights)
	{
		if (!ft_strcmp(r->light[i].type, AMBIENT))
			total_intensity += r->light[i].intensity;
		if (!ft_strcmp(r->light[i].type, POINT))
			light_dir = vec_diff(r->light[i].position, point_dir);
		if (!ft_strcmp(r->light[i].type, DIRECTIONAL))
			light_dir = r->light[i].direction;
		if ((!ft_strcmp(r->light[i].type, POINT)) || (!ft_strcmp(r->light[i].type, DIRECTIONAL)))
			total_intensity += calculate_total_intensity(r->light[i].intensity, light_dir, normal_dir);
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
