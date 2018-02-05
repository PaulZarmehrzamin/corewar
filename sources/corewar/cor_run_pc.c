/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_run_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:22:54 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/25 14:57:12 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		run_pc(t_game *game, t_cycle *cycle)
{
	t_pc	*pc;

	pc = game->pcs;
	while (pc != 0)
	{
		if (pc->wait == 0)
		{
			if ((pc->cmd)(game, pc, cycle))
				return (-1);
			pc->cmd = get_cmd((game->arena)[pc->addr]);
			pc->wait = get_wait((game->arena)[pc->addr]) - 1;
		}
		else
			(pc->wait)--;
		pc = pc->next;
	}
	return (0);
}
