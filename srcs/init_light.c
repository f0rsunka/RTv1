/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:23:31 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/07 15:17:15 by f0rsunka         ###   ########.fr       */
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
	point.position = (t_vec3){0.0f, 0.0f, 6.0f};
	point.direction = (t_vec3){0.0f, 0.0f, 0.0f};
	return (point);
}

t_light		directional_data(void)
{
	t_light directional;

	directional.type = ft_strdup(DIRECTIONAL);
	directional.intensity = 0.3;
	directional.position = (t_vec3){0.0f, 0.0f, 0.0f};
	directional.direction = (t_vec3){0.0f, -3.0f, 13.0f};
	return (directional);
}

void		light_data(t_light *light)
{
	int i;

	i = 0;
	while (i < COUNT_LIGHTS)
	{
		if (i == 0)
			light[i] = ambient_data();
		if (i == 1)
			light[i] = directional_data();
		if (i ==2)
			light[i] = point_data();
		i++;
	}
}

t_light		*init_light(void)
{
	t_light	*light;

	(COUNT_LIGHTS <= 0 ? exit(99) : 0);
	(COUNT_LIGHTS > 3 ? exit(99) : 0);
	light = (t_light*)malloc(sizeof(t_light) * COUNT_LIGHTS);
	(light == NULL ? exit(88) : 1);
	light_data(light);
	return (light);
}
