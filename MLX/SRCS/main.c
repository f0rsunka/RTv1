/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:08:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/05 22:04:07 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(void)
{
	t_rtv	*rtv;

	rtv = (t_rtv*)malloc(sizeof(t_rtv));
	(rtv == NULL ? exit (99) : 1);
	rtv->mlx = init_mlx();
	rtv->camera = init_camera();
	rtv->viewport = init_viewport();
	create_spheres(rtv);
	printf("%p\n", rtv->sphere[0]);
	// printf("center.x = %f\ncenter.y = %f\ncenter.z = %f\n", rtv->sphere[0]->center.x, rtv->sphere[0]->center.y, rtv->sphere[0]->center.z);
	draw_background(rtv);
	rtv_test(rtv);
	mlx_put_image_to_window(rtv->mlx.mptr, rtv->mlx.wptr, rtv->mlx.iptr, 0, 0);
	check_hooks_loops(rtv);
	return (0);
}
