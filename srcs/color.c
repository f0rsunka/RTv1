/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:22:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 22:28:57 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_color(t_color color)
{
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}

t_color	transform_color(t_color col)
{
	if (col.r > 1.0f && col.g > 1.0f && col.b > 1.0f)
	{
		col.r = col.r / 255;
		col.g = col.g / 255;
		col.b = col.b / 255;
	}
	else if (col.r <= 1.0f && col.g <= 1.0f && col.b <= 1.0f)
	{
		col.r = col.r * 255;
		col.g = col.g * 255;
		col.b = col.b * 255;
	}
	return (col);
}

float	transform_specular(float s)
{
	s = 255 / s;
	return (s);
}
