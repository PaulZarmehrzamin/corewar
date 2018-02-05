/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:14:54 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/30 15:38:02 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_base(t_game *game, t_pc *pc, t_cycle *cycle)
{
	(void)game;
	(void)cycle;
	pc->addr = new_addr(pc->addr, ((pc->addr + 1) % MEM_SIZE), game, pc);
	return (0);
}

void	*get_cmd2(int opcode)
{
	if (opcode == 10)
		return (&cmd_ldi);
	if (opcode == 11)
		return (&cmd_sti);
	if (opcode == 12)
		return (&cmd_fork);
	if (opcode == 13)
		return (&cmd_lld);
	if (opcode == 14)
		return (&cmd_lldi);
	if (opcode == 15)
		return (&cmd_lfork);
	if (opcode == 16)
		return (&cmd_aff);
	return (&cmd_base);
}

void	*get_cmd(int opcode)
{
	if (opcode == 1)
		return (&cmd_live);
	if (opcode == 2)
		return (&cmd_ld);
	if (opcode == 3)
		return (&cmd_st);
	if (opcode == 4)
		return (&cmd_add);
	if (opcode == 5)
		return (&cmd_sub);
	if (opcode == 6)
		return (&cmd_and);
	if (opcode == 7)
		return (&cmd_or);
	if (opcode == 8)
		return (&cmd_xor);
	if (opcode == 9)
		return (&cmd_zjmp);
	return (get_cmd2(opcode));
}
