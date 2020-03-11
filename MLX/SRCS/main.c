/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:08:37 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/11 20:57:42 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_rtv(t_rtv *rtv)
{
	rtv->mlx = init_mlx();
	rtv->camera = init_camera();
	rtv->viewport = init_viewport();
}

int		main(void)
{
	t_rtv	*rtv;

	rtv = (t_rtv*)malloc(sizeof(t_rtv));
	(rtv == NULL ? exit (99) : 1);
	init_rtv(rtv);
	init_spheres(rtv);
	check_hooks_loops(rtv);
	return (0);
}
