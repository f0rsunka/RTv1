/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:37:03 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 16:48:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

float	vec_length(t_vec3 v)
{
	float length;
	
	length = fabs(sqrtf(dot_product(v, v)));
	return (length);
}
