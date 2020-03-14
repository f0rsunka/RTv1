/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/14 21:51:08 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere **malloc_mas(int count_sphere)
{
	t_sphere **s;
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

void init_spheres(t_rtv *r)
{
	r->count_objects = 4;
	r->sphere = malloc_mas(r->count_objects);
	r->sphere[0]->center = (t_vec3){0.0, 0.0, 3.0};
	r->sphere[0]->radius = 1.0f;
	r->sphere[0]->color = PINK;
	r->sphere[1]->center = (t_vec3){2.0, -1.0, 4.0};
	r->sphere[1]->radius = 1.0f;
	r->sphere[1]->color = BLUE;
	r->sphere[2]->center = (t_vec3){-2.0, -1.0, 4.0};
	r->sphere[2]->radius = 1.0f;
	r->sphere[2]->color = PURPLE;
	r->sphere[3]->center = (t_vec3){-2.0, -1.0, 6.0};
	r->sphere[3]->radius = 5.0f;
	r->sphere[3]->color = YELLOW;
	// printf("center.x = %f\ncenter.y = %f\ncenter.z = %f\n", r->sphere[0]->center.x, r->sphere[0]->center.y, r->sphere[0]->center.z);
}
