/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rtv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:02:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 18:16:30 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	init_camera(void)
{
	t_vec3 camera;

	camera = (t_vec3){0.0, 0.0, 0.0};
	return (camera);
}

t_viewport	init_viewport(void)
{
	t_viewport viewport;

	viewport = (t_viewport){1, 1, 1};
	return (viewport);
}
