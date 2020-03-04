/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:26:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 22:35:26 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere **create_mas(void)
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

void create_mas_sphere(t_rtv *r)
{
	// t_sphere **mas_sphere;

	r->mas_sphere = create_mas();
	printf("%p\n", r->mas_sphere);
	// r->mas_sphere[0] = &((t_sphere){(t_vector3d){0, -1, 3}, 1.0, (t_color){255, 0, 0}});
	r->mas_sphere[0]->center = (t_vector3d){0.0, -1.0, 3.0};
	r->mas_sphere[0]->radius = 1.0f;
	r->mas_sphere[0]->color = (t_color){255, 0, 0};
	printf("\n%p\n", r->mas_sphere[0]);
	r->mas_sphere[1] = &((t_sphere){(t_vector3d){2, 0, 4}, 1.0, (t_color){0, 0, 255}});
	r->mas_sphere[2] = &((t_sphere){(t_vector3d){-2, 0, 4}, 1.0, (t_color){0, 255, 0}});
	printf("center.x = %f\ncenter.y = %f\ncenter.z = %f\n", r->mas_sphere[0]->center.x, r->mas_sphere[0]->center.y, r->mas_sphere[0]->center.z);
}

// t_sphere *new_sphere(t_vector3d center, double radius, t_color color)
// {
// 	t_sphere sphere;
// 	sphere->center = center;
// 	sphere->radius = radius;
// 	sphere->color = color;
// 	return (*sphere);
// }
