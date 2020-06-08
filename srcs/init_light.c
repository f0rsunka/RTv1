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
	point.intensity = 0.3;
	point.position = (t_vec3){3.0f, 3.0f, 1.0f};
	// point.position = (t_vec3){3.0f, 3.0f, -2.0f};
	point.direction = (t_vec3){0.0f, 0.0f, 0.0f};
	return (point);
}

t_light		directional_data(void)
{
	t_light directional;

	directional.type = ft_strdup(DIRECTIONAL);
	directional.intensity = 0.3;
	directional.direction = (t_vec3){1.0f, 3.0f, -3.0f};
	// directional.direction = (t_vec3){4.0f, 3.0f, -3.0f};
	directional.position = (t_vec3){0.0f, 0.0f, 0.0f};
	return (directional);
}

void		light_data(t_light *light)
{
	light[0] = ambient_data();
	light[1] = directional_data();
	light[2] = point_data();
}

t_light		*init_light(void)
{
	t_light	*light;

	(COUNT_LIGHTS == 0 ? exit(12): 0);
	light = (t_light*)malloc(sizeof(t_light) * COUNT_LIGHTS);
	(light == NULL ? exit (88) : 1);
	light_data(light);
	return (light);
}
