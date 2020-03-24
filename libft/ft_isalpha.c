/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:49:15 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/14 22:26:46 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int		ft_isalpha(int ch)
{
	return (((ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z')) ? 1 : 0);
}