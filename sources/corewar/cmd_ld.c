/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:49:51 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/31 17:38:17 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_ld(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;
	int		isind;

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	isind = tab[1];
	next = get_next_addr(pc->addr, tab, 4, 2);
	if ((tab[1] == 2 || tab[1] == 3) && tab[2] == 1)
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 2)
		{
			if (isind == 3)
				tab[1] = (int)read_nb(game->arena,
					pc->addr + (tab[1] % IDX_MOD), 4);
			pc->reg[tab[2]] = tab[1];
			pc->carry = (pc->reg[tab[2]] == 0 ? 1 : 0);
		}
	}
	pc->addr = new_addr(pc->addr, next, game, pc);
	return (0);
}

int		cmd_lld(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;
	int		isind;

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	isind = tab[1];
	next = get_next_addr(pc->addr, tab, 4, 2);
	if ((tab[1] == 2 || tab[1] == 3) && tab[2] == 1)
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 2)
		{
			if (isind == 3)
				tab[1] = (int)read_nb(game->arena,
					pc->addr + tab[1], 4);
			pc->reg[tab[2]] = tab[1];
			pc->carry = (pc->reg[tab[2]] == 0 ? 1 : 0);
		}
	}
	pc->addr = new_addr(pc->addr, next, game, pc);
	return (0);
}

int		cmd_ldi(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;
	int		isreg[2];

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	isreg[0] = tab[1];
	isreg[1] = tab[2];
	next = get_next_addr(pc->addr, tab, 2, 3);
	if (tab[1] != 0 && (tab[2] == 1 || tab[2] == 2) && tab[3] == 1)
	{
		if (get_param_value(game->arena, pc->addr, tab, 2) > 3)
		{
			if (isreg[0] == 3)
				tab[1] = (int)read_nb(game->arena, pc->addr + tab[1], 4);
			tab[1] = isreg[0] == 1 ? pc->reg[tab[1]] : tab[1];
			tab[2] = isreg[1] == 1 ? pc->reg[tab[2]] : tab[2];
			pc->reg[tab[3]] = (int)read_nb(game->arena,
					pc->addr + (tab[1] + tab[2]) % IDX_MOD, 4);
		}
	}
	pc->addr = new_addr(pc->addr, next, game, pc);
	return (0);
}

int		cmd_lldi(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;
	int		isreg[2];

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	isreg[0] = tab[1];
	isreg[1] = tab[2];
	next = get_next_addr(pc->addr, tab, 2, 3);
	if (tab[1] != 0 && (tab[2] == 1 || tab[2] == 2) && tab[3] == 1)
	{
		if (get_param_value(game->arena, pc->addr, tab, 2) > 3)
		{
			if (isreg[0] == 3)
				tab[1] = (int)read_nb(game->arena, pc->addr + tab[1], 4);
			tab[1] = isreg[0] == 1 ? pc->reg[tab[1]] : tab[1];
			tab[2] = isreg[1] == 1 ? pc->reg[tab[2]] : tab[2];
			pc->reg[tab[3]] = (int)read_nb(game->arena,
					pc->addr + (tab[1] + tab[2]), 4);
			pc->carry = (pc->reg[tab[3]] == 0 ? 1 : 0);
		}
	}
	pc->addr = new_addr(pc->addr, next, game, pc);
	return (0);
}
