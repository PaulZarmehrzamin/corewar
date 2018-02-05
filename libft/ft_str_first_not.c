/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_first_not.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:45:05 by mressier          #+#    #+#             */
/*   Updated: 2017/10/30 14:39:55 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_first(const char *str, int (*ft_is)(int))
{
	char	*ptr;

	ptr = (char *)str;
	while (ptr && *ptr && !ft_is(*ptr))
		ptr++;
	return (ptr);
}

char	*ft_str_first_not(const char *str, int (*ft_is)(int))
{
	char	*ptr;

	ptr = (char *)str;
	while (ptr && *ptr && ft_is(*ptr))
		ptr++;
	return (ptr);
}
