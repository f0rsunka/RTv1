/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:32:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/16 19:15:44 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H
# include <math.h>

typedef struct 		s_vec3
{	
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct 		s_ivec3
{	
	int				x;
	int				y;
	int				z;
}					t_ivec3;

typedef struct		s_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct		s_ivec2
{
	int				x;
	int				y;
}					t_ivec2;

/*
** *********************************** **
** *********************************** **
**            vector_operations        **
** *********************************** **
** *********************************** **
*/

t_vec3 		vec_diff(t_vec3 v1, t_vec3 v2);
double		dot_product(t_vec3 v1, t_vec3 v2);
t_vec3 		vec_add(t_vec3 v1, t_vec3 v2);
t_vec3		vec_normalize(t_vec3 v);
t_vec3		mult_vec_const(t_vec3 v, float n);
float		vec_length(t_vec3 v);

#endif