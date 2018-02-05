/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:56:07 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 17:42:08 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		set_cycle_data(unsigned int cycles, WINDOW *box)
{
	wattron(box, COLOR_PAIR(5));
	mvwprintw(box, POS_HEAD_INFO, POS_C_CYCLE, "%d      ", cycles);
	wattroff(box, COLOR_PAIR(5));
}

void		set_process_data(unsigned int process, WINDOW *box)
{
	wattron(box, COLOR_PAIR(5));
	mvwprintw(box, POS_HEAD_INFO, POS_C_NB_PC, "%d      ", process);
	wattroff(box, COLOR_PAIR(5));
}

void		set_cycle_to_die(unsigned int cycle_die, WINDOW *box)
{
	wattron(box, COLOR_PAIR(5));
	mvwprintw(box, POS_HEAD_INFO, POS_C_CYCLEDIE, "%d      ", cycle_die);
	wattroff(box, COLOR_PAIR(5));
}

void		set_max_check(unsigned int check, WINDOW *box)
{
	wattron(box, COLOR_PAIR(5));
	mvwprintw(box, POS_HEAD_INFO, POS_C_MAX_CHECK, "%d/%d      ",
														check, MAX_CHECKS);
	wattroff(box, COLOR_PAIR(5));
}

void		set_winner(int index, WINDOW *box)
{
	int		pos;

	pos = ((POS_C_PLAYER * index) + MARGIN) - 7;
	wattron(box, COLOR_PAIR(index));
	mvwprintw(box, POS_HEAD_PLAYER, pos, "WIN -> ");
	wattroff(box, COLOR_PAIR(index));
}
