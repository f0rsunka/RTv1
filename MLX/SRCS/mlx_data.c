/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:59:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/11 20:58:00 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;
	int		bp;
	int		size_line;
	int		endian;
	
	if (!(mlx.mptr = mlx_init()))
		exit(99);
	if (!(mlx.wptr = mlx_new_window(mlx.mptr, WIN_W, WIN_H, "RTV1\0")))
		exit(99);
	if (!(mlx.iptr = mlx_new_image(mlx.mptr, WIN_W, WIN_H)))
		exit(99);
	if (!(mlx.img = (int*)mlx_get_data_addr(mlx.iptr, &bp, &size_line, &endian)))
		exit(99);
	return (mlx);
}

int		draw_all_hook(t_rtv *r)
{
	mlx_clear_window(r->mlx.mptr, r->mlx.wptr);
	render_sphere(r);
	mlx_put_image_to_window(r->mlx.mptr, r->mlx.wptr, r->mlx.iptr, 0, 0);
	return (0);
}

void	check_hooks_loops(t_rtv *r)
{
	mlx_loop_hook(r->mlx.mptr, &draw_all_hook, &r->mlx);
	mlx_hook(r->mlx.wptr, 2, 0, &key_press, &r->mlx);
	mlx_hook(r->mlx.wptr, 17, 0, &close_hook, &r->mlx);
	// mlx_hook(r->mlx.wptr, 3, 0, &key_unpress, &r->mlx);
	mlx_loop(r->mlx.mptr);
}
