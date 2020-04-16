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
	sphere[0].color = transform_color(PINK);
	// sphere[0].center = (t_vec3){0.0, 0.0, 3.0};
	sphere[0].center = (t_vec3){0.0, -1.0, 3.0};
	sphere[0].radius = 1.0f;
	sphere[0].specular = transform_specular(800.0f);
	// sphere[0].specular = 500.0f;



	sphere[1].color = transform_color(BLUE);
	// sphere[1].center = (t_vec3){1.2, 0.0, 3.0};
	sphere[1].center = (t_vec3){-2.0, 1.0, 3.0};
	sphere[1].radius = 1.0f;
	// sphere[1].specular = 500.0f;
	sphere[1].specular = transform_specular(800.0f);



	sphere[2].color = transform_color(PURPLE);
	// sphere[2].center = (t_vec3){-1.2f, 0.0, 3.0};
	sphere[2].center = (t_vec3){2.0f, 1.0, 3.0};
	sphere[2].radius = 1.0f;
	// sphere[2].specular = 500.0f;
	sphere[2].specular = transform_specular(800.0f);

	// sphere[3].color = transform_color(YELLOW);
	// sphere[3].center = (t_vec3){0.0f, 24.9f, 17.0f};
	// sphere[3].radius = 30.1f;
	// sphere[3].specular = transform_specular(100.0f);
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
