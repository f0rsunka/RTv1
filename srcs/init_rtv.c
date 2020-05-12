/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rtv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:02:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 15:26:21 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_camera(t_rtv *r)
{
	r->camera.dir = (t_vec3){1.0f, 1.0f, 1.0f};
	r->camera.angle = (t_vec3){0.0f, 0.0f, 0.0f};
	r->camera.was_pressed = 0;
}

// t_viewport	init_viewport(void)
// {
// 	t_viewport viewport;

// 	viewport = (t_viewport){1, 1, 1};
// 	return (viewport);
// }
