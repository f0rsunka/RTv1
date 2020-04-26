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

float	calculate_intensity(float light_intensity, t_vec3 light_dir, t_intersect intersect, t_vec3 view)
{
	float	intensity;
	t_vec3 light;

	light = vec_normalize(light_dir);
	intensity = 0.0f;
	intensity += calculate_diffuse(light_intensity, light, intersect.normal); //* intersect.s.sphere->material.a.x;
	// if (intersect.material.specular >= 0)
	// 	intensity += calculate_reflection(view, light_dir, light_intensity, intersect) * intersect.s.sphere->material.a.y;
	return (intensity);
}

float	calculate_lightning(t_rtv *r, t_vec3 dir, t_intersect intersect, t_vec3 p)
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
			total_intensity += calculate_intensity(r->light[i].intensity, light_dir, intersect, dir);
		i++;
	}
	if (total_intensity > 1.0f)
		total_intensity = 1.0f;
	return (total_intensity);
}

t_vec3		get_normal_sphere(t_vec3 hit, t_vec3 center_sphere)
{
	t_vec3	normal;
	t_vec3	normal_dir;
	
	normal = vec_diff(center_sphere, hit);
	normal_dir = vec_normalize(normal);
	return (normal_dir);
}

float		get_light(t_closest_sphere closest, t_vec3 dir, t_rtv *r)
{
	t_intersect intersect;
	t_vec3		reverse_dir;
	float		intensity;
	t_vec3		hit;

	intersect.s = closest;
	// reverse_dir = vec_add_const(dir, -1);
	hit = vec_add(r->camera, vec_add_const(dir, closest.dist));
	intersect.normal = get_normal_sphere(hit, closest.sphere->center);
	intersect.material = closest.sphere->material;
	// intensity = calculate_lightning(r, dir, normal_dir, closest.sphere->material.specular, p);
	intensity = calculate_lightning(r, reverse_dir, intersect, hit);
	return (intensity);
}

t_color	add_light(t_color col, t_closest_sphere closest, t_vec3 dir, t_rtv *r)
{
	float intensity;

	intensity = get_light(closest, dir, r);
	col.r *= intensity;
	col.g *= intensity;
	col.b *= intensity;
	return (col);
}

t_color	ogo_light()
{

}