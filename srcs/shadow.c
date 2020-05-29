/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:19:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/13 20:37:30 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		is_shadow(t_rtv *r)
{
	t_closest_obj		closest;
	t_scene				*tmp;
	t_scene				*current;

	closest.dist = FLT_MAX;
	closest.obj = NULL;
	current = r->scene;
	while (current != NULL)
	{
		if (current->type == SPHERE)
			sphere_intersect(r, current, &closest);
		if (current->type == CYLINDER)
			cylinder_intersect(r, current, &closest);
		if (current->type == CONE)
			cone_intersect(r, current, &closest);
		// if (current->type == PLANE_1)
		// 	plane_intersect_1(r, current, &closest);
		// if (current->type == PLANE_2)
		// 	plane_intersect_2(r, current, &closest);
		// if (current->type == PLANE_3)
		// 	plane_intersect_3(r, current, &closest);
		tmp = current->next;
		current = tmp;
	}
	if (closest.obj == NULL)
		return (0);
	return (1);
}
