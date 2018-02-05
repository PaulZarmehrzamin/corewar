/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:08:13 by mressier          #+#    #+#             */
/*   Updated: 2017/10/30 14:40:25 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Search the last occurence of the char c in the string s.
**	It return a pointer on it, or NULL if it's not int the string
*/

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

void		*ft_memrchr(const void *mem_start, const void *mem_end, int c)
{
	int		i;

	i = mem_end - mem_start;
	if (i < 0)
		return (NULL);
	while (i >= 0)
	{
		if (((unsigned char *)mem_start)[i] == (unsigned char)c)
			return ((char *)&mem_start[i]);
		i--;
	}
	return (NULL);
}
