/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_lightning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 00:01:13 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 00:10:12 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	calculate_types_light(t_rtv *r, t_light light, t_material material,
								float *intensity)
{
	calculate_diffuse(light, r->ray.normal, intensity);
	if (material.specular >= 0)
		calculate_specular(r, light, material.specular, intensity);
}

void	calculate_diffuse(t_light light, t_vec3 normal, float *intensity)
{
	float dot_l_n;
	float len_l;
	float len_n;

	dot_l_n = dot_product(light.direction, normal);
	if (dot_l_n > 0)
	{
		len_l = vec_length(light.direction);
		len_n = vec_length(normal);
		*intensity += light.intensity * dot_l_n / (len_l * len_n);
	}
	else
		*intensity += 0.01;
}

void	calculate_specular(t_rtv *r, t_light light, float specular,
															float *intensity)
{
	t_vec3	spec;
	float	dot_l_n;
	float	dot_r_v;
	float	len_r;
	float	len_v;

	dot_l_n = dot_product(light.direction, r->ray.normal);
	if (r->closest.type == TYPE_CONE)
		spec = vec_diff(mult_vec_const(r->ray.normal, dot_l_n * 2.0f),
															light.direction);
	else
		spec = vec_diff(light.direction,
						mult_vec_const(r->ray.normal, dot_l_n * 2.0f));
	dot_r_v = dot_product(spec, r->ray.dir);
	if (dot_r_v > 0)
	{
		len_r = vec_length(spec);
		len_v = vec_length(r->ray.dir);
		*intensity += light.intensity *
									powf((dot_r_v / (len_r * len_v)), specular);
	}
	else
		*intensity += 0.01;
}
