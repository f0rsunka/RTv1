/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:19:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/04 22:47:52 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		is_shadow(t_rtv *r)
{
	t_closest_obj		closest;
	t_scene				*tmp;
	t_scene				*current;

	closest_zero(&closest);
	current = r->scene;
	while (current != NULL)
	{
		if (current->type == SPHERE)
			sphere_intersect(r, current, &closest);
		if (current->type == CYLINDER)
			cylinder_intersect(r, current, &closest);
		if (current->type == PLANE)
		{
			plane_intersect(r, current, &closest);
			// printf("\n\n%f\n", closest.dist);
		}
		tmp = current->next;
		current = tmp;
	}
	if (closest.obj == NULL)
		return (-1.0f);
	// printf("1. %f\n", closest.dist);
	return (closest.dist);
}
