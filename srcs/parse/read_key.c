/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 20:01:21 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/09 20:01:50 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		read_keyed_double(char *line, char *key, double *data)
{
	char	*str;

	str = ft_strstr(line, key);
	if (line == str && str != 0)
	{
		*data = ft_atod(line + ft_strlen(key));
		return (1);
	}
	return (0);
}

int		read_keyed_float(char *line, char *key, float *data)
{
	char	*str;

	str = ft_strstr(line, key);
	if (line == str && str != 0)
	{
		*data = (float)ft_atod(line + ft_strlen(key));
		return (1);
	}
	return (0);
}

int		read_keyed_int(char *line, char *key, int *data)
{
	char	*str;

	str = ft_strstr(line, key);
	if (line == str && str != 0)
	{
		*data = (int)ft_atoi(line + ft_strlen(key));
		return (1);
	}
	return (0);
}
