/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_diff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:48:59 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/08 00:44:15 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libvector.h"

t_vec3 	vec_diff(t_vec3 v1, t_vec3 v2)
{
	t_vec3 diff;

	diff.x = v1.x - v2.x;
	diff.y = v1.y - v2.y;
	diff.z = v1.z - v2.z;
	return (diff);
}
