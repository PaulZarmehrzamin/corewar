/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:55:02 by mressier          #+#    #+#             */
/*   Updated: 2017/01/17 19:00:06 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return true or false if two strings are equals
*/

#include <stdbool.h>
#include <string.h>

int			ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!n || (s1 == NULL && s2 == NULL))
		return (true);
	if (s1 == NULL || s2 == NULL)
		return (false);
	while (*s1 == *s2 && *s1 && *s2 && --n)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (true);
	return (false);
}
