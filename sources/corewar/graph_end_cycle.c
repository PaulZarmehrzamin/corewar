/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_end_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:12:56 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 14:37:52 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	make_wait_cycles(int speed)
{
	useconds_t	val;

	val = 0;
	if (speed == 25)
		val = 40000;
	if (speed == 50)
		val = 20000;
	if (speed == 100)
		val = 10000;
	if (speed == 200)
		val = 5000;
	if (speed == 250)
		val = 4000;
	if (speed == 1000)
		val = 1000;
	usleep(val);
}

void		display_end_cycle(t_game *game, t_cycle *cycle)
{
	set_cycle_data(cycle->current, game->display->head);
	set_process_data(game->nb_pc, game->display->head);
	set_cycle_to_die(cycle->to_die, game->display->head);
	set_max_check(cycle->nb_check, game->display->head);
	wrefresh(game->display->head);
	wrefresh(game->display->box);
	make_wait_cycles(game->speed);
}
