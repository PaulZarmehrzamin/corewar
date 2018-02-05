/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:52:46 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 15:01:54 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnum(const char *str)
{
	int		index;

	if (str == NULL)
		return (0);
	if (str[0] != '-' && ft_isdigit(str[0]) != 1)
		return (0);
	index = 1;
	while (str[index])
	{
		if (ft_isdigit(str[index]) != 1)
			return (0);
		index++;
	}
	return (1);
}
