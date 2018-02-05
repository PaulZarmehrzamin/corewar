/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_addsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:40:56 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/30 18:19:41 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_add(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	next = get_next_addr(pc->addr, tab, 4, 3);
	if (tab[1] == 1 && tab[2] == 1 && tab[3] == 1)
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 3)
		{
			pc->reg[tab[3]] = pc->reg[tab[1]] + pc->reg[tab[2]];
			pc->carry = (pc->reg[tab[3]] == 0 ? 1 : 0);
		}
	}
	pc->addr = new_addr(pc->addr, next, game, pc);
	return (0);
}

int		cmd_sub(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	next = get_next_addr(pc->addr, tab, 4, 3);
	if (tab[1] == 1 && tab[2] == 1 && tab[3] == 1)
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 3)
		{
			pc->reg[tab[3]] = pc->reg[tab[1]] - pc->reg[tab[2]];
			pc->carry = (pc->reg[tab[3]] == 0 ? 1 : 0);
		}
	}
	pc->addr = new_addr(pc->addr, next, game, pc);
	return (0);
}
