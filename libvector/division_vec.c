/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 00:43:50 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/08 00:43:53 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libvector.h"

t_vec3	division_vec(t_vec3 v1, t_vec3 v2)
{
	t_vec3 v;

	if (v2.x != 0.0f && v2.y != 0.0f && v2.z != 0.0f)
	{
		v.x = v1.x / v2.x;
		v.y = v1.y / v2.y;
		v.z = v1.z / v2.z;
		return (v);
	}
	else
		return (v1);
}
