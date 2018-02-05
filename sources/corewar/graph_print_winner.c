/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_print_winner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:59:14 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 17:33:06 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_win(t_game *game)
{
	int			index;
	t_player	*begin;

	index = 1;
	begin = game->players;
	while (begin)
	{
		if (begin->live == game->winner)
			set_winner(index, game->display->head);
		begin = begin->next;
		index++;
	}
}

void			graph_print_winner(t_game *game)
{
	get_win(game);
	wrefresh(game->display->head);
}
