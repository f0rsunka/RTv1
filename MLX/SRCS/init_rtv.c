/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rtv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:02:16 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/14 21:51:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// light {
//     type = ambient
//     intensity = 0.2
// }
// light {
//     type = point
//     intensity = 0.6
//     position = (2, 1, 0)
// }
// light {
//     type = directional
//     intensity = 0.2
//     direction = (1, 4, 4)
// }

t_light	init_light(void)
{
	// t_light light_point;
	t_light	light_ambient;

	light_ambient.intensity = 0.7;
	// light_point.position = (t_vec3){-20.0f, 20.0f, 20.0f};
	// light_point.intensity = 1.5f;
	return (light_ambient);
}

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
