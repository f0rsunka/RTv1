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

void	calculate_types_light(t_rtv *r, t_light light, t_material material, float *intensity)
{
	float diffuse_int = 0.0f;
	float spec_int = 0.0f;

	calculate_diffuse(light, r->ray.normal, intensity);
	// printf("\n\n***\nbefore = %f\n", *intensity);
	// *intensity *= material.a.x;
	if (material.specular >= 0)
	{
		calculate_reflection(r->ray, light, material.specular, intensity);
	// 	*intensity *= material.a.y;
		// printf("\nafter  = %f\n", *intensity);
	}
	// printf("%f\n", *intensity);
	// printf("ray->normal = %f %f %f\n", r->ray.normal);
}

void	iterate_light(t_rtv *r, t_material material, float *intensity)
{
	int		i;

	i = 0;
	while (i < COUNT_LIGHTS)
	{
		if (!ft_strcmp(r->light[i].type, POINT))
		{
			// r->light[i].position = mult_vec_const(r->light[i].direction, -1);
			r->light[i].direction = vec_diff(r->ray.p, r->light[i].position);
		}
		if (!ft_strcmp(r->light[i].type, DIRECTIONAL))
		{
			r->light[i].direction = r->light[i].direction;
		}
		if (!ft_strcmp(r->light[i].type, AMBIENT))
		{
			*intensity += r->light[i].intensity;
		}
		else
		{
			// r->light[i].direction = mult_vec_const(r->light[i].direction, -1);
			calculate_types_light(r, r->light[i], material, intensity);
		}
		i++;
	}
	if (*intensity > 1.0f)
		*intensity = 1.0f;
	// printf("aft %f\n", *intensity);
}

t_color calculate_lightning(t_rtv *r, t_closest_obj closest)
{
	float	intensity;
	t_color	col;

	intensity = 0.0f;
	r->ray.reverse_dir = mult_vec_const(r->ray.dir, -1);
	// r->ray.p = vec_add(r->camera, mult_vec_const(r->ray.dir, closest.dist));
	r->ray.p = vec_add(r->camera, mult_vec_const(r->ray.reverse_dir, closest.dist));
	// r->ray.p = mult_vec_const(r->ray.p, -1);
	// printf("%f\n", closest.dist);
	r->ray.normal = get_normal_sphere(r->ray.p, ((t_sphere *)closest.obj)->center);
	// r->ray.normal = mult_vec_const(r->ray.normal, -1);
	// printf("bef %f\n", intensity);
	iterate_light(r, ((t_sphere *)closest.obj)->material, &intensity);
	add_light(((t_sphere *)closest.obj)->material.color, &col, intensity);
	return (col);
}

void	add_light(t_color col, t_color *res_col, float intensity)
{
	res_col->r = col.r * intensity;
	res_col->g = col.g * intensity;
	res_col->b = col.b * intensity;
	// col.r *= intensity;
	// col.g *= intensity;
	// col.b *= intensity;
	// return (res_col);
}
