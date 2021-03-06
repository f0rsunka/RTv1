/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:02:59 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/12 15:10:12 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "SDL.h"
# include "libvector.h"
# include "libft.h"
# include "structs.h"
# include "prototypes.h"
# include "errors.h"
# include <stdlib.h>
# include <math.h>

# define WIN_W 900
# define WIN_H 700

/*
** *********************************** **
** *********************************** **
**         libs for reading            **
** *********************************** **
** *********************************** **
*/

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** *********************************** **
** *********************************** **
**            math value               **
** *********************************** **
** *********************************** **
*/

# define FOV (M_PI / 2.0)
# define DEG2RAD (M_PI / 180.f)
# define EPSILON 1e-16

/*
** *********************************** **
** *********************************** **
**            count anything           **
** *********************************** **
** *********************************** **
*/

# define COUNT_PRIMITIVES 6
# define COUNT_LIGHTS 3

/*
** *********************************** **
** *********************************** **
**            primitives               **
** *********************************** **
** *********************************** **
*/

# define TYPE_HEAD 0
# define TYPE_PLANE 1
# define TYPE_SPHERE 2
# define TYPE_CONE 3
# define TYPE_CYLINDER 4

/*
** *********************************** **
** *********************************** **
**               color                 **
** *********************************** **
** *********************************** **
*/

# define PURPLE (t_color){191, 164, 255}
# define BLUE (t_color){181, 188, 255}
# define PINK (t_color){217, 188, 255}
# define YELLOW (t_color){255, 255, 0}
# define LILAC (t_color){131, 120, 158}
# define BACKGROUND_COLOR float_to_byte(LILAC)
# define BRIGHT_PURPLE (t_color){172, 159, 255}
# define VINOUS (t_color){255, 158, 210}
# define GRAY (t_color){125, 125, 125}
// # define BRIGHT_PURPLE (t_color){186, 151, 255}
# define LIGHT_GRAY (t_color){200, 200, 200}
# define ROSE_PINK (t_color){255, 165, 198}
# define INDEPENDENCE (t_color){202, 211, 255}
# define INDIGO (t_color){196, 214, 255}

/*
** *********************************** **
** *********************************** **
**           type of lights            **
** *********************************** **
** *********************************** **
*/

# define LIGHT_TYPE_HEAD		0
# define LIGHT_TYPE_AMBIENT		1
# define LIGHT_TYPE_POINT		2
# define LIGHT_TYPE_DIRECTIONAL	3

#endif
