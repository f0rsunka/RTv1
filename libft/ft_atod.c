/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:19:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/06/11 01:39:48 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "include/libft.h"

static double	ft_res(const char *str, size_t i)
{
	double			total;
	size_t			del;
	unsigned char	should_count_del;

	total = 0;
	del = 0;
	should_count_del = 0;
	while ((str[i] >= '0' && str[i] <= '9' && str[i] != '\0') || str[i] == '.')
	{
		if (str[i] == '.')
		{
			should_count_del = 1;
			i++;
			continue;
		}
		total = total * 10 + (str[i] - 48);
		if (should_count_del)
		{
			del++;
		}
		i++;
	}
	return (total / pow(10, del));
}

double			ft_atod(const char *str)
{
	double		total;
	size_t		i;
	int			flag;

	i = 0;
	flag = 0;
	while ((str[i] != '\0') && (str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	total = ft_res(str, i);
	total = (flag == -1) ? (total * (-1)) : total;
	return (total);
}
