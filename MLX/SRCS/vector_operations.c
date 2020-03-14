/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:44:13 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/14 21:36:33 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3 	vec_diff(t_vec3 v1, t_vec3 v2)
{
	t_vec3 diff;

	diff.x = v2.x - v1.x;
	diff.y = v2.y - v1.y;
	diff.z = v2.z - v1.z;
	return (diff);
}

double	dot_product(t_vec3 v1, t_vec3 v2)
{
	double dp;

	dp = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dp);
}

t_vec3 	vec_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3 v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vec3 vec_add_const(t_vec3 v, float n)
{
	return ((t_vec3){v.x * n, v.y * n, v.z * n});
}

float	vec_length(t_vec3 v)
{
	float length;
	
	length = sqrt(dot_product(v, v));
	return (length);
}

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
