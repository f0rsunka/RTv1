/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:02:59 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/14 21:44:50 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
#include "structs.h"
#include "prototypes.h"
#include "../MinilibX/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h> //!---------------------------------------------------------
# define WIN_W 1800
# define WIN_H 1000

# define FOV M_PI / 2.0
# define DX(W)(W / 2.0)
# define DY(H)(H / 2.0)

# define T_MAX 100000.0
# define FLT_MAX 930000.0

# define PINK (t_color){191, 164, 255}
# define BLUE (t_color){174, 196, 255}
# define PURPLE (t_color){255, 222, 222}
# define YELLOW (t_color){255, 255, 0}

# define BACKGROUND_COLOR (t_color){131, 120, 158}

/*
** *********************************** **
** *********************************** **
**         defines for mlx             **
** *********************************** **
** *********************************** **
*/

# define KEY_ESC 53
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

#endif
