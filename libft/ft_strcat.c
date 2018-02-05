/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:42:25 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 16:42:40 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int a;
	int b;

	if (!s2 || s2 == NULL)
		return (s1);
	b = ft_strlen(s1);
	a = 0;
	while (s2[a] != '\0')
	{
		s1[b] = s2[a];
		b++;
		a++;
	}
	s1[b] = '\0';
	return (s1);
}
