/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:05:08 by cvernius          #+#    #+#             */
/*   Updated: 2019/09/24 01:10:34 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		create_line(char **line, int i, char **balance)
{
	char *tmp;

	i = 0;
	if (**balance && *balance)
	{
		while ((*balance)[i] && (*balance)[i] != '\n')
			++i;
		if (!(*line = ft_strsub(*balance, 0, i)))
			return (-1);
		if (i != (int)ft_strlen(*balance))
		{
			if (!(tmp = ft_strsub(*balance, i + 1, (ft_strlen(*balance) - i))))
				return (-1);
			free(*balance);
			*balance = tmp;
		}
		else
		{
			free(*balance);
			*balance = NULL;
		}
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*balance[MAX_FD + 1];
	int			red;
	char		*tmp_fir;
	char		*alpha;
	int			i;

	if (fd > MAX_FD || line == NULL)
		return (-1);
	if (!(balance[fd])) 									/* есть ли массив чаров, cодержащий остаток считанного */
		if (!(balance[fd] = ft_strnew(0)))					/*  случае если ее нет, попытка создать строчку состоящую только из \0 */
			return (-1);
	/* Например, если мы считали от fd = 3 десять символов "564/n666989", то в остатке после вызова функции будет 666989 */
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = 0;
		buf[red] = '\0';
		alpha = ft_memchr(buf, '\n', red);
		i = alpha - buf;
		if (!(tmp_fir = ft_strjoin(balance[fd], buf)))
			return (-1);
		free(balance[fd]);
		balance[fd] = tmp_fir;
		if (i != red)
			return (create_line(line, i, &balance[fd]));
	}
	return (red < 0 ? -1 : create_line(line, i, &balance[fd]));
}
