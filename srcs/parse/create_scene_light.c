/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f0rsunka <f0rsunka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 20:23:18 by f0rsunka          #+#    #+#             */
/*   Updated: 2020/06/10 00:11:16 by f0rsunka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*create_scene_light(int fd, char **line)
{
	char	*str;
	t_light *tmp;

	str = ft_strstr(*line, "  light:");
	if (*line == str && str != 0)
	{
		tmp = (t_light *)malloc(sizeof(t_light));
		(tmp == NULL ? rtv_error(MALLOC_ERROR) : 0);
		parse_light(fd, line, tmp);
		tmp->next = 0;
		return (tmp);
	}
	return (0);
}
