/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 17:51:27 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere_data(t_sphere *sphere)
{
	sphere[0].color = PINK;
	sphere[0].center = (t_vec3){0.0, 0.0, 3.0};
	sphere[0].radius = 1.0f;
	sphere[1].color = BLUE;
	sphere[1].center = (t_vec3){2.0, -1.0, 4.0};
	sphere[1].radius = 1.0f;
	sphere[2].color = PURPLE;
	sphere[2].center = (t_vec3){-2.0, -1.0, 4.0};
	sphere[2].radius = 1.0f;
	// sphere[3].color = YELLOW;
	// sphere[3].center = (t_vec3){0.0, -10.0, 4.0};
	// sphere[3].radius = 39.0f;
}

t_sphere *init_sphere(t_rtv *r)
{
	t_sphere *s;

	r->count_objects = 3;
	s = (t_sphere*)malloc(sizeof(t_sphere) * r->count_objects);
	(s == NULL ? exit (88) : 0);
	sphere_data(s);
	return (s);
}
