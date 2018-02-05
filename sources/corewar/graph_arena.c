/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:25:46 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 17:01:46 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_remove_head(int index, t_game *game, int id)
{
	int		line;
	int		col;

	id = 0;
	wattron(game->display->box, COLOR_PAIR(id));
	line = ((index / NB_OCTET_GRAPH) + 4);
	col = ((index % NB_OCTET_GRAPH) * 3) + 1;
	mvwprintw(game->display->box, line, col, " ",
						(unsigned char)game->arena[index]);
	wattroff(game->display->box, COLOR_PAIR(id));
}

void			print_head_read(int index, t_game *game, int id)
{
	int		line;
	int		col;

	id = id + 9;
	wattron(game->display->box, COLOR_PAIR(id));
	line = ((index / NB_OCTET_GRAPH) + 4);
	col = ((index % NB_OCTET_GRAPH) * 3) + 1;
	mvwprintw(game->display->box, line, col, ">",
						(unsigned char)game->arena[index]);
	wattroff(game->display->box, COLOR_PAIR(id));
}

void			move_head(int new_index, int old_index, t_game *game, int id)
{
	int			real_index;

	print_head_read(new_index, game, id);
	real_index = ((new_index + 1) % MEM_SIZE);
	print_remove_head(old_index, game, id);
}

void			print_char(int index, t_game *game, int id)
{
	int		line;
	int		col;

	wattron(game->display->box, COLOR_PAIR(id));
	line = (index / NB_OCTET_GRAPH) + 4;
	col = ((index % NB_OCTET_GRAPH) * 3) + 2;
	mvwprintw(game->display->box, line, col, "%02x ",
									(unsigned char)game->arena[index]);
	wattroff(game->display->box, COLOR_PAIR(id));
}

void			print_int(int index, t_game *game, int id)
{
	int		line;
	int		col;
	int		octets;
	int		real_index;

	octets = 0;
	wattron(game->display->box, COLOR_PAIR(id));
	while (octets < 4)
	{
		real_index = ((index + octets) % MEM_SIZE);
		line = (real_index / NB_OCTET_GRAPH) + 4;
		col = ((real_index % NB_OCTET_GRAPH) * 3) + 2;
		mvwprintw(game->display->box, line, col, "%02x ",
									(unsigned char)game->arena[real_index]);
		octets++;
	}
	wattroff(game->display->box, COLOR_PAIR(id));
}
