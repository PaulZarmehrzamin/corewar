/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:48:52 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/30 19:38:23 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	destroy_pc(t_pc *pc, t_game *game)
{
	if (game->verb == -1)
		print_remove_head(pc->addr, game, pc->id_player);
	free(pc);
	print_pc_kill(game);
	(game->nb_pc)--;
}

void	check_first_pc(t_cycle *cycle, t_game *game)
{
	t_pc	*tmp;

	if (cycle->current >= game->pcs->last_live + cycle->to_die)
	{
		tmp = game->pcs;
		game->pcs = game->pcs->next;
		destroy_pc(tmp, game);
	}
}

void	check_pc(t_cycle *cycle, t_game *game)
{
	t_pc	*ptr;
	t_pc	*tmp;

	if (game->pcs == NULL)
		return ;
	ptr = game->pcs;
	tmp = game->pcs->next;
	while (tmp != 0)
	{
		if (cycle->current >= tmp->last_live + cycle->to_die)
		{
			tmp = tmp->next;
			destroy_pc(ptr->next, game);
			ptr->next = tmp;
		}
		else
		{
			tmp = tmp->next;
			ptr = ptr->next;
		}
	}
	check_first_pc(cycle, game);
}

void	reset_cycle(t_cycle *cycle, t_game *game)
{
	cycle->to_die -= CYCLE_DELTA;
	print_cycle_to_die(game, cycle->to_die);
	cycle->check += cycle->to_die;
	cycle->nb_check = 0;
}

void	check_cycle(t_cycle *cycle, t_game *game)
{
	if (cycle->current == cycle->check)
	{
		if (game->nb_live >= NBR_LIVE)
			reset_cycle(cycle, game);
		else
		{
			(cycle->nb_check)++;
			if (cycle->nb_check == MAX_CHECKS)
			{
				reset_cycle(cycle, game);
			}
			else
				cycle->check += cycle->to_die;
		}
		if (cycle->to_die <= 0)
			print_cycle_current(game, cycle->current);
		game->nb_live = 0;
		check_pc(cycle, game);
	}
}
