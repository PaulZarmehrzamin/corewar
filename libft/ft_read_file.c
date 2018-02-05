/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:50:00 by mressier          #+#    #+#             */
/*   Updated: 2017/10/30 14:40:52 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

#define BUF_READ	(2048 * 8)

int			ft_read_file(int fd, char **out_content)
{
	char		*content;
	char		*temp;
	char		buf[BUF_READ + 1];
	int			ret;
	int			size;

	if (out_content == NULL || fd == -1)
		return (-1);
	content = ft_strdup("");
	size = 0;
	while ((ret = read(fd, buf, BUF_READ)) > 0 && size >= 0)
	{
		buf[ret] = '\0';
		temp = ft_memjoin(content, size, buf, ret + 1);
		ft_memdel((void **)&content);
		content = temp;
		size += ret;
	}
	*out_content = content;
	if (ret < 0 || size < 0)
		return (-1);
	return (size);
}

int			ft_read_file_with_filename(const char *filename,
				char **out_content)
{
	int		size;
	int		fd;

	if (filename == NULL || out_content == NULL)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = ft_read_file(fd, out_content);
	close(fd);
	return (size);
}
