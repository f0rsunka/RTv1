/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:35:33 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 16:36:03 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vec3	vec_normalize(t_vec3 v)
{
	float length;
	t_vec3 nor_v;

	length = vec_length(v);
	nor_v.x = v.x / length;
	nor_v.y = v.y / length;
	nor_v.z = v.z / length;
	return (nor_v);
}
