/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_diff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:48:59 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 16:49:24 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libvector.h"

t_vec3 	vec_diff(t_vec3 v1, t_vec3 v2)
{
	t_vec3 diff;

	diff.x = v2.x - v1.x;
	diff.y = v2.y - v1.y;
	diff.z = v2.z - v1.z;
	return (diff);
}
