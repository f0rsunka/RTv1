/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/05 21:34:58 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere **malloc_mas(void)
{
	t_sphere **s;
	int count_sphere = 3;
	int i = 0;

	if (!(s = (t_sphere**)malloc(sizeof(t_sphere*) * 3)))
		return (NULL);
	while (i < count_sphere)
	{
		s[i] = (t_sphere*)malloc(sizeof(t_sphere));
		(s[i] == NULL ? exit(99) : 1);
		i++;
	}
	return (s);
}

void create_spheres(t_rtv *r)
{
	r->sphere = malloc_mas();
	// printf("%p\n", r->sphere);
	r->sphere[0]->center = (t_vec3){0.0, -2.0, 3.0};
	r->sphere[0]->radius = 1.0f;
	r->sphere[0]->color = (t_color){191, 164, 255};		//pink
	// printf("\n%p\n", r->sphere[0]);
	
	r->sphere[1]->center = (t_vec3){2.0, 0.0, 4.0};
	r->sphere[1]->radius = 1.0f;
	r->sphere[1]->color = (t_color){174, 196, 255};		// blue

	r->sphere[2]->center = (t_vec3){-2.0, 0.0, 4.0};
	r->sphere[2]->radius = 1.0f;
	r->sphere[2]->color = (t_color){255, 222, 222};		//purple

	r->count_objects = 3;
	printf("center.x = %f\ncenter.y = %f\ncenter.z = %f\n", r->sphere[0]->center.x, r->sphere[0]->center.y, r->sphere[0]->center.z);
}
