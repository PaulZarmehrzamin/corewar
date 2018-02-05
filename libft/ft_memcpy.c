/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 12:06:46 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 15:38:05 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp_dst;
	char	*tmp_src;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	while (i < (n - 1))
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	tmp_dst[i] = tmp_src[i];
	return (dst);
}
