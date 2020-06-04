/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:19:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/04 18:07:03 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_closest_obj		is_shadow(t_rtv *r)
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
		closest.dist = -1.0;
	return (closest);
}
