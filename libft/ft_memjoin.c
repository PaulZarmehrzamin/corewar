/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 13:14:16 by mressier          #+#    #+#             */
/*   Updated: 2017/10/30 14:39:06 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Take two memories and create a new allocate memory by concatenate s1-s2
*/

#include "libft.h"

void			*ft_memjoin(const void *p1, size_t s1, const void *p2,
																size_t s2)
{
	void		*new_mem;

	if (p1 == NULL || p2 == NULL)
		return (NULL);
	new_mem = ft_memalloc(s1 + s2);
	if (new_mem == NULL)
		return (new_mem);
	new_mem = ft_memcpy(new_mem, p1, s1);
	ft_memcpy(new_mem + s1, p2, s2);
	return (new_mem);
}
