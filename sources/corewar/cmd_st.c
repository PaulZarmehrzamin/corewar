/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:31:14 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/11/02 10:39:45 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		write_arena(t_game *game, int addr1, int addr2, int n)
{
	int		addr;

	addr = (addr1 + addr2) % MEM_SIZE;
	while (addr < 0)
		addr += MEM_SIZE;
	game->arena[addr] = (n >> 24) & 0xFF;
	game->arena[(addr + 1) % MEM_SIZE] = (n >> 16) & 0xFF;
	game->arena[(addr + 2) % MEM_SIZE] = (n >> 8) & 0xFF;
	game->arena[(addr + 3) % MEM_SIZE] = n & 0xFF;
	return (addr);
}

void	print_st(int addr, t_game *game, int id)
{
	if (game->verb == -1)
		print_int(addr, game, id);
}

int		cmd_st(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;
	int		addr;

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	next = get_next_addr(pc->addr, tab, 4, 2);
	if (tab[1] == 1 && tab[2] == 1)
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 2)
			pc->reg[tab[2]] = pc->reg[tab[1]];
	}
	else if (tab[1] == 1 && tab[2] == 3)
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 2)
		{
			addr = write_arena(game, pc->addr,
				tab[2] % IDX_MOD, pc->reg[tab[1]]);
			print_st(addr, game, pc->id_player);
		}
	}
	pc->addr = new_addr(pc->addr, next, game, pc);
	return (0);
}

int		cmd_sti(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;
	int		addr;
	int		isreg[2];

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	isreg[0] = tab[2];
	isreg[1] = tab[3];
	next = get_next_addr(pc->addr, tab, 2, 3);
	if (tab[1] == 1 && tab[2] != 0 && (tab[3] == 1 || tab[3] == 2))
	{
		if (get_param_value(game->arena, pc->addr, tab, 2) > 3)
		{
			if (isreg[0] == 3)
				tab[2] = (int)read_nb(game->arena, pc->addr + tab[2], 4);
			tab[2] = isreg[0] == 1 ? pc->reg[tab[2]] : tab[2];
			tab[3] = isreg[1] == 1 ? pc->reg[tab[3]] : tab[3];
			addr = write_arena(game, pc->addr,
				(tab[2] + tab[3]) % IDX_MOD, pc->reg[tab[1]]);
			print_st(addr, game, pc->id_player);
		}
	}
	pc->addr = new_addr(pc->addr, next, game, pc);
	return (0);
}
