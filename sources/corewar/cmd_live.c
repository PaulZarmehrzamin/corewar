/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:11:32 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/30 14:59:11 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_player(t_player *player, int live)
{
	if (!player)
		return (0);
	if (player->live == live)
		return (1);
	return (is_player(player->next, live));
}

int		cmd_live(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int			live;

	live = (int)read_nb(game->arena, pc->addr + 1, 4);
	pc->last_live = cycle->current;
	if (is_player(game->players, live))
	{
		game->winner = live;
		print_pc_live(game, live);
	}
	(game->nb_live)++;
	pc->addr = new_addr(pc->addr, ((pc->addr + 5) % MEM_SIZE), game, pc);
	return (0);
}
