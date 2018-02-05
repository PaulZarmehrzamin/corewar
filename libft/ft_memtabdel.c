/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:46:50 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 18:47:53 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memtabdel(void ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		ft_memdel((void *)&(*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
