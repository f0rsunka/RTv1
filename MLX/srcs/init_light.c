/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:23:31 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 20:31:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void light_data(t_light *light)
{
	t_light	ambient;
	t_light	point;
	t_light directional;

	ambient.type = (char *)malloc(sizeof(char) * 8);
	(ambient.type == NULL ? exit (88) : 0);
	ambient.type = ft_strdup(AMBIENT);
	ambient.intensity = 0.3;
	point.type = (char *)malloc(sizeof(char) * 6);
	(point.type == NULL ? exit (88) : 0);
	point.type = ft_strdup(POINT);
	point.intensity = 0.5;
	point.position = (t_vec3){2.0f, 1.0f, 0.0f};
	directional.type = (char *)malloc(sizeof(char) * 12);
	(directional.type == NULL ? exit (88) : 0);
	directional.type = ft_strdup(DIRECTIONAL);
	directional.intensity = 0.2;
	directional.direction = (t_vec3){1.0, 4.0, 4.0};
	light[0] = ambient;
	light[1] = point;
	light[2] = directional;
	// return (light);
}

t_light	*init_light(t_rtv *r)
{
	t_light	*light;

	r->count_lights = 3;
	light = (t_light*)malloc(sizeof(light) * r->count_lights);
	(light == NULL ? exit (88) : 1);
	light_data(light);
	printf("light,type = %s\nintens = %f\n", light[1].type, light[1].intensity);
	return (light);
}
