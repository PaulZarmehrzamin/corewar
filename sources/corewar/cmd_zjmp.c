/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:00:43 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/11/02 10:40:38 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_zjmp(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		old_addr;

	old_addr = pc->addr;
	(void)cycle;
	if (pc->carry)
	{
		pc->addr += (short)read_nb(game->arena, pc->addr + 1, 2) % IDX_MOD;
	}
	else
		pc->addr += 3;
	pc->addr = pc->addr % MEM_SIZE;
	while (pc->addr < 0)
		pc->addr += MEM_SIZE;
	if (game->verb == -1)
		move_head(pc->addr, old_addr, game, pc->id_player);
	return (0);
}
