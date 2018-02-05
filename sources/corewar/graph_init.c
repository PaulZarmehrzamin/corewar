/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:56:17 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 17:44:52 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_color_set(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, 107, COLOR_BLACK);
	init_pair(8, 208, COLOR_BLACK);
	init_pair(9, 238, COLOR_BLACK);
	init_pair(10, 255, COLOR_GREEN);
	init_pair(11, 255, COLOR_CYAN);
	init_pair(12, 255, COLOR_RED);
	init_pair(13, 255, COLOR_BLUE);
	init_pair(14, 255, COLOR_YELLOW);
	init_pair(15, 255, COLOR_MAGENTA);
	init_pair(16, 255, 107);
	init_pair(17, 255, 208);
}

static void		print_player(WINDOW *box, t_player *players)
{
	t_player	*begin;
	int			index;
	int			pos;
	char		buff[MAX_LEN_NAME + 1];

	index = 1;
	begin = players;
	while (begin)
	{
		ft_bzero(buff, MAX_LEN_NAME + 1);
		ft_memcpy(buff, begin->name, MAX_LEN_NAME);
		pos = ((POS_C_PLAYER * index) + MARGIN);
		wattron(box, COLOR_PAIR(index));
		mvwprintw(box, POS_HEAD_PLAYER, pos, begin->name);
		wattroff(box, COLOR_PAIR(index));
		index++;
		begin = begin->next;
	}
}

static void		print_header(t_game *game)
{
	wattron(game->display->head, COLOR_PAIR(5));
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_CYCLE - 9),
															"cycles : PAUSED");
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_NB_PC - 10),
															"process : ");
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_CYCLEDIE - 15),
															"cycle to die : ");
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_MAX_CHECK - 8),
															"check : ");
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_SPEED - 8),
															"speed : ");
	wattroff(game->display->head, COLOR_PAIR(5));
	set_process_data(game->nb_pc, game->display->head);
	set_cycle_to_die(CYCLE_TO_DIE, game->display->head);
	set_cycle_to_die(0, game->display->head);
	set_speed(game->speed, game->display->head);
	print_player(game->display->head, game->players);
}

int				init_window(t_game *game)
{
	initscr();
	if (LINES < MAX_L || COLS < MAX_C)
	{
		error(TOOSMALL, 0);
		game->verb = 0;
		endwin();
		return (0);
	}
	start_color();
	game->display = init_display();
	noecho();
	curs_set(0);
	init_color_set();
	box(game->display->head, ACS_VLINE, ACS_HLINE);
	box(game->display->box, ACS_VLINE, ACS_HLINE);
	print_header(game);
	print_arena_start(game);
	wrefresh(game->display->box);
	wrefresh(game->display->head);
	return (0);
}

int				clear_window(t_display *display)
{
	while (getch() != 27)
		;
	endwin();
	release_display(display);
	return (0);
}
