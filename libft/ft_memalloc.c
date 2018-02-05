/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 11:32:49 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 15:37:59 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dst;
	size_t	i;

	if (!size)
		return (NULL);
	i = 0;
	dst = malloc(sizeof(dst) * (size));
	if (!dst)
		return (NULL);
	while (i < size)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
