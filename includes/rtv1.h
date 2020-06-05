/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:02:59 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/05 14:23:06 by f0rsunka         ###   ########.fr       */
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
// # define WIN_W 1024
// # define WIN_H 768

# define WIN_W 700
# define WIN_H 500

# define M_PI 3.14159265358979323846
# define FOV (M_PI / 2.0)
# define DEG2RAD (M_PI / 180.f)
// # define EPSILON 1e-16

/*
** *********************************** **
** *********************************** **
**            count anything           **
** *********************************** **
** *********************************** **
*/

# define COUNT_PRIMITIVE 5
# define COUNT_LIGHTS 3

/*
** *********************************** **
** *********************************** **
**            primitives               **
** *********************************** **
** *********************************** **
*/

# define SPHERE 20
# define PLANE 90
# define CYLINDER 30
# define CONE 40

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
# define BRIGHT_PURPLE (t_color){186, 151, 255}
# define ROSE_PINK (t_color){255, 112, 165}
# define INDEPENDENCE (t_color){224, 215, 255}

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



// # define MAX_X 1.398
// # define MAX_Y 0.998
// # define DIST_MAX (MAX_X + MAX_Y * WIN_W)

#endif
