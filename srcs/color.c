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

t_color	float_to_byte(t_color col)
{
	col.r = col.r / 255;
	col.g = col.g / 255;
	col.b = col.b / 255;
	return (col);
}

t_color	byte_to_float(t_color col)
{
	col.r = col.r * 255;
	col.g = col.g * 255;
	col.b = col.b * 255;
	return (col);	
}

int		compare_color(t_color c1, t_color c2)
{
	if (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)
		return (1);
	else if (c1.r != c2.r && c1.g != c2.g && c1.b != c2.b)
		return (0);
	return (1);
}
