/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:07:40 by mressier          #+#    #+#             */
/*   Updated: 2017/10/30 14:39:29 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmemory(void *mem, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = mem;
	while (i < size)
	{
		ft_putchar(ptr[i]);
		i++;
	}
}
