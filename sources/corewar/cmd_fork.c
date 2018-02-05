/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:40:44 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/11/02 10:40:53 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		fork_cpy(t_game *game, t_pc *pc, int new_addr)
{
	t_pc	*fork;

	fork = (t_pc *)malloc(sizeof(t_pc));
	if (!fork)
		return (error(MALLOC_FAILED, -1));
	fork = ft_memcpy(fork, pc, sizeof(t_pc));
	fork->next = game->pcs;
	game->pcs = fork;
	fork->addr += new_addr;
	fork->addr %= MEM_SIZE;
	while (fork->addr < 0)
		fork->addr += MEM_SIZE;
	if (game->verb == -1)
		print_head_read(fork->addr, game, fork->id_player);
	fork->cmd = get_cmd((game->arena)[fork->addr]);
	fork->wait = get_wait((game->arena)[fork->addr]) - 1;
	(game->nb_pc)++;
	return (0);
}

int		cmd_fork(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		new_addr_fork;

	(void)cycle;
	new_addr_fork = (short)read_nb(game->arena, pc->addr + 1, 2) % IDX_MOD;
	if (fork_cpy(game, pc, new_addr_fork) == -1)
		return (-1);
	pc->addr = new_addr(pc->addr, ((pc->addr + 3) % MEM_SIZE), game, pc);
	return (0);
}

int		cmd_lfork(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		new_addr_fork;

	(void)cycle;
	new_addr_fork = (short)read_nb(game->arena, pc->addr + 1, 2);
	if (fork_cpy(game, pc, new_addr_fork) == -1)
		return (-1);
	pc->addr = new_addr(pc->addr, ((pc->addr + 3) % MEM_SIZE), game, pc);
	return (0);
}
