/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:15:13 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/05 15:17:01 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	calculate_specular(t_ray ray, t_light light, float specular, float *intensity)
{
	t_vec3	spec;
	float	dot_l_n;
	float	dot_r_v;
	float	len_r;
	float	len_v;

	dot_l_n = dot_product(light.direction, ray.normal);
	spec = vec_diff(light.direction, mult_vec_const(ray.normal, dot_l_n * 2.0f));
	dot_r_v = dot_product(spec, ray.dir);
	if (dot_r_v > 0)
	{
		len_r = vec_length(spec);
		len_v = vec_length(ray.dir);
		*intensity += light.intensity * powf((dot_r_v / (len_r * len_v)), specular);
	}
	else
		*intensity += 0.01;
}
