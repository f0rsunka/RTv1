/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:00:15 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/05 22:14:26 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3 canvas_to_viewport(t_ivec2 coord, t_viewport v)
{
	t_vec3 point_3d;

	point_3d.x = coord.x * v.w / WIN_W;
	point_3d.y = coord.y * v.h / WIN_H;
	point_3d.z = v.d;
	// D = (t_vec3*){(coord.x * v.x / WIN_W), (coord.y * v.y / WIN_H), d};
	return (point_3d);
}

void	rtv_test(t_rtv *r)
{
	t_ivec2	coord;
	t_color	color;

	coord = (t_ivec2){- WIN_W / 2, - WIN_H / 2};
	while (coord.x < WIN_W / 2)
	{
		coord.y = - WIN_H / 2;
		while (coord.y < WIN_H / 2)
		{
			r->point_in_3d = canvas_to_viewport(coord, r->viewport);
			color = trace_ray(r->camera, r->point_in_3d, 1, r);
			// printf("color === %d %d %d\n", color.r, color.g, color.b);
			// printf("dig = %d\n", WIN_W / 2 + (int)coord.x + (WIN_H / 2 - (int)coord.y) * WIN_W);
			if (WIN_W / 2 + coord.x + (WIN_H / 2 - coord.y) * WIN_W <= WIN_W * WIN_H
				&& WIN_W / 2 + coord.x + (WIN_H / 2 - coord.y) * WIN_W >= 0)
				// {
					r->mlx.img[WIN_W / 2 + coord.x + (WIN_H / 2 - coord.y) * WIN_W]
					= get_color((t_color)(color));
				// }
			printf("coord = %d ***\ncolor = {%d, %d, %d}\n\n", WIN_W / 2 + coord.x + (WIN_H / 2 - coord.y) * WIN_W, color.r, color.g, color.b);
			sleep(1);
			coord.y++;
		}
		coord.x++;
	}
}
