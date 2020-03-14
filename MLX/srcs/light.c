/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:36:57 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/14 21:45:54 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// now i compile ONLY with ambient lightning

float	calculate_lightning(t_rtv *r, t_vec3 dir, t_vec3 vec_n)
{
	float count_lights;

	count_lights = 0.0f;
	count_lights += r->light.intensity;
	return (count_lights);
}

t_color	color_with_light(t_color col, float count_lights)
{
	col.r *= count_lights;
	col.g *= count_lights;
	col.b *= count_lights;
	return (col);
}
