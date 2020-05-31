/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:14:34 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/05/31 17:14:36 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
