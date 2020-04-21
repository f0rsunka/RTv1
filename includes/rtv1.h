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
# define WIN_W 1000
# define WIN_H 600
# define FOV (M_PI / 2.0)
// # define EPSILON 1e-16
# define SPHERE 0
# define SPHERE 1
# define SPHERE 2
# define PLACE 3
# define CONE 4
# define CYLINDER 5
# define COUNT_PRIMITIVE 6

/*
** *********************************** **
** *********************************** **
**               color                 **
** *********************************** **
** *********************************** **
*/

// # define PINK (t_color){191, 164, 255}
// # define BLUE (t_color){174, 196, 255}
// # define PURPLE (t_color){255, 202, 249}
// # define YELLOW (t_color){255, 255, 0}
# define BACKGROUND_COLOR (t_color){131, 120, 158}

# define PURPLE (t_color){191, 164, 255}
# define BLUE (t_color){174, 196, 255}
// # define PURPLE (t_color){255, 202, 249}
# define PINK (t_color){255, 202, 249}
// # define PINK (t_color){24, 67, 249}
# define YELLOW (t_color){255, 255, 0}

/*
** *********************************** **
** *********************************** **
**           type of lights            **
** *********************************** **
** *********************************** **
*/

# define AMBIENT "ambient\0"
# define POINT "point\0"
# define DIRECTIONAL "directional\0"

#endif
