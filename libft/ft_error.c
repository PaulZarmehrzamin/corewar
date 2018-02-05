/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:40:41 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/08/22 15:20:10 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_fd(int status, char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(status);
}

void	ft_error(int status, char *str)
{
	ft_putstr_fd(str, 2);
	exit(status);
}
