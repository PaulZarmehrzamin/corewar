/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:00:26 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 15:38:14 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char	*ret;
	int		s_cmp;
	int		r_cmp;

	s_cmp = 0;
	r_cmp = 0;
	if (!str || str == NULL)
		return (NULL);
	while (str[s_cmp] == ' ' || str[s_cmp] == '\n' || str[s_cmp] == '\t')
		s_cmp++;
	if ((ret = (char *)malloc(ft_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[s_cmp] != '\0')
	{
		ret[r_cmp] = str[s_cmp];
		r_cmp++;
		s_cmp++;
	}
	ret[r_cmp] = '\0';
	r_cmp--;
	while (r_cmp >= 0 && (ret[r_cmp] == ' ' || ret[r_cmp] == '\n'
											|| ret[r_cmp] == '\t'))
		r_cmp--;
	ret[r_cmp + 1] = '\0';
	return (ret);
}
