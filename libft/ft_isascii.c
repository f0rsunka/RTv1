/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:52:14 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/03 15:31:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int		ft_isascii(int ch)
{
	return ((ch >= 0 && ch <= 0x7F) ? 1 : 0);
}
