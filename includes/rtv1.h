/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:02:59 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/17 16:32:34 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "SDL.h"
# include "../libvector/include/libvector.h"
# include "../libft/include/libft.h"
# include "structs.h"
# include "prototypes.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h> //!---------------------------------------------------------
# define M_PI 3.14159265358979323846
# define WIN_W 1024
# define WIN_H 768

// # define WIN_W 700
// # define WIN_H 500


int			intersect_ray_plane_2(t_plane plane, t_vec3 camera, t_vec3 dir, float *plane_dist);

int 		intersect_ray_plane_3(t_plane plane, t_vec3 camera, t_vec3 dir, float *plane_dist);

int 		intersect_ray_plane_1(t_plane plane, t_vec3 camera, t_vec3 dir, float *plane_dist);


# define FOV (M_PI / 2.0)
// # define EPSILON 1e-16

# define SPHERE 20
# define PLANE_1 90
# define PLANE_2 91
# define PLANE_3 92
# define CYLINDER 30
# define CONE 40
# define COUNT_PRIMITIVE 1
# define COUNT_LIGHTS 3
# define DEG2RAD (M_PI / 180.f)

/*
** *********************************** **
** *********************************** **
**               color                 **
** *********************************** **
** *********************************** **
*/

# define PURPLE (t_color){191, 164, 255}
# define BLUE (t_color){174, 196, 255}
# define PINK (t_color){255, 202, 249}
# define YELLOW (t_color){255, 255, 0}
# define LILAC (t_color){131, 120, 158}
# define BACKGROUND_COLOR float_to_byte(LILAC)
# define BRIGHT_PURPLE (t_color){172, 159, 255}
# define VINOUS (t_color){255, 158, 210}
# define GRAY (t_color){125, 125, 125}

/*
** *********************************** **
** *********************************** **
**           type of lights            **
** *********************************** **
** *********************************** **
*/

# define AMBIENT "a"
# define POINT "p"
# define DIRECTIONAL "d"

#endif
