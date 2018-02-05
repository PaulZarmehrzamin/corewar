/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:10:56 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 14:12:30 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	print_arena_player(t_game *game, t_player *player, int index,
																	int id)
{
	int				next_player;
	unsigned int	size_player;
	int				nb_player;
	t_player		*begin;

	begin = game->players;
	nb_player = count_my_player(begin);
	next_player = MEM_SIZE / nb_player;
	size_player = player->size_prog;
	while (next_player > 0)
	{
		if (size_player > 0)
		{
			print_char(index, game, id);
			size_player--;
		}
		else
			print_char(index, game, 9);
		index++;
		next_player--;
	}
	return (index);
}

static void	print_end_arena(int index, t_game *game)
{
	while (index < MEM_SIZE)
	{
		print_char(index, game, 9);
		index++;
	}
}

static void	print_head(t_pc *pcs, t_game *game)
{
	t_pc	*begin;

	begin = pcs;
	while (begin)
	{
		print_head_read(begin->addr, game, begin->id_player);
		begin = begin->next;
	}
}

void		print_arena_start(t_game *game)
{
	t_player		*begin;
	int				nb_player;
	int				index;
	int				my_current_id;

	index = 0;
	begin = game->players;
	my_current_id = 1;
	nb_player = count_my_player(begin);
	while (begin)
	{
		index = print_arena_player(game, begin, index, my_current_id);
		my_current_id++;
		begin = begin->next;
	}
	print_end_arena(index, game);
	print_head(game->pcs, game);
}
