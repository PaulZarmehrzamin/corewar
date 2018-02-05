/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:21:53 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 17:54:54 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_parsing(char *s, int n, int sign, size_t i)
{
	s[i--] = '\0';
	if (n == INT_MIN)
		s[i--] = 56;
	else
		s[i--] = (sign * n % 10) + 48;
	while ((n = n / 10))
	{
		s[i] = (sign * n % 10) + 48;
		i--;
	}
	if (sign == -1)
		s[i] = '-';
	return (s);
}

char		*ft_itoa(int n)
{
	size_t	i;
	int		n_;
	int		sign;
	char	*s;

	i = 1;
	n_ = n;
	sign = 1;
	if (n < 0)
		sign = -1;
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	if (sign == -1)
		i++;
	s = (char *)malloc(sizeof(s) * (i + 1));
	if (!s)
		return (NULL);
	n = n_;
	s = ft_parsing(s, n, sign, i);
	return (s);
}
