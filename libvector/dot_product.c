/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:36:27 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 16:36:49 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libvector.h"

double	dot_product(t_vec3 v1, t_vec3 v2)
{
	double dp;

	dp = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dp);
}
