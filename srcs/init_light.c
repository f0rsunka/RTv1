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

void	get_type(char *cnst, char *res)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(cnst);
	while (i < n)
	{
		res[i] = cnst[i];
		i++;
	}
	res[i] = '\0';
}

void	light_data(t_light *light)
{
	t_light	ambient;
	t_light	point;
	t_light directional;

	ambient.type = (char *)malloc(sizeof(char) * ft_strlen(AMBIENT) + 1);
	(ambient.type == NULL ? exit (88) : 0);
	get_type(AMBIENT, ambient.type);
	ambient.intensity = 0.2;
	ambient.position = (t_vec3){0.0f, 0.0f, 0.0f};
	ambient.direction = (t_vec3){0.0f, 0.0f, 0.0f};

	point.type = (char *)malloc(sizeof(char) * ft_strlen(POINT) + 1);
	(point.type == NULL ? exit (88) : 0);
	get_type(POINT, point.type);
	point.intensity = 0.6;
	// point.position = (t_vec3){-1.0f, -4.0f, 5.0f};
	point.position = (t_vec3){2.0, 1.0, 0.0f};
	point.direction = (t_vec3){0.0f, 0.0f, 0.0f};

	directional.type = (char *)malloc(sizeof(char) * ft_strlen(DIRECTIONAL) + 1);
	(directional.type == NULL ? exit (88) : 0);
	get_type(DIRECTIONAL, directional.type);
	directional.intensity = 0.2;
	directional.direction = (t_vec3){1.0, 4.0, 4.0f};
	directional.position = (t_vec3){0.0f, 0.0f, 0.0f};

	light[0] = ambient;
	light[1] = point;
	// light[1] = directional;
	light[2] = directional;
}

t_light	*init_light(t_rtv *r)
{
	t_light	*light;

	r->count_lights = 3;
	light = (t_light*)malloc(sizeof(light) * r->count_lights);
	(light == NULL ? exit (88) : 1);
	light_data(light);
	return (light);
}
