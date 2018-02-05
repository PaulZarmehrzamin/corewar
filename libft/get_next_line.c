/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 21:09:54 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/08/22 15:22:08 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_stock(char **stock, int fd)
{
	if (!stock[fd])
	{
		if (!(stock[fd] = (char *)malloc(sizeof(char))))
			return (-1);
		stock[fd][0] = '\0';
	}
	return (0);
}

static int	check_stock(int fd, char **stock, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(stock[fd], '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(stock[fd]);
		tmp = ft_strdup(tmp + 1);
		free(stock[fd]);
		stock[fd] = tmp;
		return (1);
	}
	return (0);
}

static int	check_buffer(char *buf, int fd, char **stock, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(stock[fd], buf);
		free(stock[fd]);
		stock[fd] = ft_strdup(tmp + 1);
		return (1);
	}
	tmp = ft_strjoin(stock[fd], buf);
	free(stock[fd]);
	stock[fd] = tmp;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*stock[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || fd == 1 || fd == 2 || fd >= FD_MAX || line == NULL)
		return (-1);
	if (get_stock(stock, fd))
		return (-1);
	if (check_stock(fd, stock, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (check_buffer(buf, fd, stock, line))
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (!ft_strlen(stock[fd]))
		return (0);
	*line = ft_strdup(stock[fd]);
	free(stock[fd]);
	stock[fd] = NULL;
	return (1);
}
