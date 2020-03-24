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
#define M_PI 3.14159265358979323846
# define WIN_W 800
# define WIN_H 600
# define FOV (M_PI / 2.0)
// # define FLT_MAX 930000.0

/*
** *********************************** **
** *********************************** **
**         defines for mlx             **
** *********************************** **
** *********************************** **
*/
// # ifdef __APPLE__
// # define KEY_ESC 53
// #endif

// #ifdef __linux__
// # define KEY_ESC 65307
// #endif

// # define KEY_1 18
// # define KEY_2 19
# define KEY_SPACE 49
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13
# define KEY_ARROW_UP 126
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define ENTER 36

/*
** *********************************** **
** *********************************** **
**               color                 **
** *********************************** **
** *********************************** **
*/

# define PINK (t_color){191, 164, 255}
# define BLUE (t_color){174, 196, 255}
# define PURPLE (t_color){255, 202, 249}
# define YELLOW (t_color){255, 255, 0}
# define BACKGROUND_COLOR (t_color){131, 120, 158}

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
