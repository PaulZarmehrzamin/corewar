/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:34:03 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/11/02 10:49:47 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		new_addr(int old_addr, int new_addr, t_game *game, t_pc *pc)
{
	if (game->verb == -1)
		move_head(new_addr, old_addr, game, pc->id_player);
	return (new_addr);
}

int		read_nb(char *arena, int addr, int size)
{
	int		tmp;

	tmp = 0;
	while (size > 0)
	{
		tmp = tmp << 8;
		tmp += (unsigned char)(arena[addr % MEM_SIZE]);
		addr++;
		size--;
	}
	return (tmp);
}

void	get_param_code(char *arena, int addr, int *tab)
{
	int		i;

	tab[0] = arena[(addr + 1) % MEM_SIZE];
	i = 1;
	while (i < 4)
	{
		tab[i] = (tab[0] >> (6 - (i - 1) * 2)) & 3;
		i++;
	}
}

int		get_next_addr(int addr, int *tab, int size, int nb)
{
	int		i;
	int		next;

	i = 1;
	next = 2;
	while (i <= nb && i < 4)
	{
		if (tab[i] == 1)
			next++;
		else if (tab[i] == 2)
			next += size;
		else if (tab[i] == 3)
			next += 2;
		i++;
	}
	return ((addr + next) % MEM_SIZE);
}

int		get_param_value(char *arena, int addr, int *tab, int size)
{
	int		i;

	i = 0;
	while (++i < 4)
	{
		if (tab[i] == 1)
		{
			tab[i] = (unsigned char)read_nb(arena, addr + 2, 1) - 1;
			if (!(tab[i] >= 0 && tab[i] < REG_NUMBER))
				return (i);
			addr++;
		}
		else if (tab[i] == 2)
		{
			tab[i] = (size == 2 ? (short)read_nb(arena, addr + 2, 2) :
				(int)read_nb(arena, addr + 2, 4));
			addr += size;
		}
		else if (tab[i] == 3)
		{
			tab[i] = (short)read_nb(arena, addr + 2, 2);
			addr += 2;
		}
	}
	return (4);
}
