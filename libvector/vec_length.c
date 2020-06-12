/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:37:03 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/10 11:10:40 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libvector.h"

float	vec_length(t_vec3 v)
{
	float length;

	length = fabs(sqrtf(dot_product(v, v)));
	return (length);
}
