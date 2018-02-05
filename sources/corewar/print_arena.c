/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:00:48 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 16:38:26 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			print_offset(unsigned int index)
{
	char	res[7];
	int		cmp;
	int		len;

	len = LEN_HEXA;
	if (index == 0 || len == 0)
		return (ft_putstr("0x0000"));
	cmp = 5;
	res[6] = '\0';
	while ((index / len) > 0 || cmp >= 5)
	{
		res[cmp] = BASE_HEXA[(index % len)];
		index /= len;
		cmp--;
	}
	res[cmp] = BASE_HEXA[(index % len)];
	cmp--;
	while (cmp >= 0)
	{
		res[cmp] = BASE_HEXA[0];
		cmp--;
	}
	res[0] = '0';
	res[1] = 'x';
	ft_putstr(res);
}

static void			print_hexa(void *ptr)
{
	unsigned char	c;
	char			res[3];
	int				len;
	int				cmp;

	c = *(char *)ptr;
	len = LEN_HEXA;
	if (c == 0 || len == 0)
		return (ft_putstr("00"));
	cmp = 1;
	res[2] = '\0';
	while ((c / len) > 0 || cmp >= 1)
	{
		res[cmp] = BASE_HEXA[(c % len)];
		c /= len;
		cmp--;
	}
	res[cmp] = BASE_HEXA[(c % len)];
	cmp--;
	while (cmp >= 0)
	{
		res[cmp] = BASE_HEXA[0];
		cmp--;
	}
	ft_putstr(res);
}

void				print_arena(const char *arena, int nb_octet)
{
	unsigned int	index;
	size_t			cmp;
	int				nl;

	nl = 0;
	index = 0;
	cmp = 0;
	print_offset(index);
	ft_putstr(" : ");
	while (cmp < MEM_SIZE)
	{
		if (nl == nb_octet)
		{
			index = index + nb_octet;
			ft_putchar('\n');
			print_offset(index);
			ft_putstr(" : ");
			nl = 0;
		}
		print_hexa((void *)&arena[cmp]);
		ft_putchar(' ');
		cmp++;
		nl++;
	}
	ft_putchar('\n');
}
