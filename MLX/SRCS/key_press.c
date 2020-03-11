/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:01:17 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/11 20:51:03 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_press(int k, t_rtv *r)
{
	(k == KEY_ESC ? exit(88) : 1);
	// mlx_clear_window(r->mlx.mptr, r->mlx.wptr);
	// // (k == KEY_W ? rtv_test(r) : 1);
	render_sphere(r);
	mlx_put_image_to_window(r->mlx.mptr, r->mlx.wptr, r->mlx.iptr, 0, 0);
	return (0);
}

int		close_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
