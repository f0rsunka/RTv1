/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 00:44:03 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 11:09:59 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libvector.h"

t_vec3	mult_matrix(t_vec3 a, t_vec3 b)
{
	t_vec3 c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}
