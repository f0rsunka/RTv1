/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:23:31 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 17:45:59 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		ambient_data(void)
{
	t_light	ambient;

	ambient.type = ft_strdup(AMBIENT);
	ambient.intensity = 0.4;
	ambient.position = (t_vec3){0.0f, 0.0f, 0.0f};
	ambient.direction = (t_vec3){0.0f, 0.0f, 0.0f};
	return (ambient);
}

t_light		point_data(void)
{
	t_light	point;

	point.type = ft_strdup(POINT);
	point.intensity = 0.2;
	point.position = (t_vec3){-2.5f, -1.0f, -3.0f};
	// point.position = (t_vec3){3.3f, -1.0f, -3.0f};
	point.direction = (t_vec3){0.0f, 0.0f, 0.0f};
	return (point);
}

t_light		directional_data(void)
{
	t_light directional;

	directional.type = ft_strdup(DIRECTIONAL);
	directional.intensity = 0.4;
	directional.direction = (t_vec3){9.0f, 6.0f, 7.0f};
	directional.position = (t_vec3){0.0f, 0.0f, 0.0f};
	return (directional);
}

void		light_data(t_light *light)
{
	light[0] = ambient_data();
	light[1] = point_data();
	light[2] = directional_data();
}

t_light		*init_light(t_rtv *r)
{
	t_light	*light;

	r->count_lights = 3;
	light = (t_light*)malloc(sizeof(t_light) * r->count_lights);
	(light == NULL ? exit (88) : 1);
	light_data(light);
	return (light);
}
