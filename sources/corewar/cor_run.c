/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:29:35 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/11/02 10:23:55 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_cycle(t_cycle *cycle)
{
	cycle->current = 1;
	cycle->to_die = CYCLE_TO_DIE;
	cycle->check = CYCLE_TO_DIE + 1;
	cycle->nb_check = 0;
}

void	init_pc(t_game *game)
{
	t_pc	*pc;

	pc = game->pcs;
	while (pc != 0)
	{
		pc->cmd = get_cmd((game->arena)[pc->addr]);
		pc->wait = get_wait((game->arena)[pc->addr]) - 1;
		pc = pc->next;
	}
}

void	present_player(t_game *game)
{
	t_player	*tmp;
	int			i;

	if (game->verb != -1)
	{
		ft_putstr("Introducing contestants...\n");
		i = 1;
		tmp = game->players;
		while (tmp != 0)
		{
			ft_putstr("-> Player ");
			ft_putnbr(i);
			ft_putstr(", weighing ");
			ft_putnbr(tmp->size_prog);
			ft_putstr(" bytes, live = ");
			ft_putnbr(tmp->live);
			ft_putstr(" : \"");
			ft_putstr(tmp->name);
			ft_putstr("\" (");
			ft_putstr(tmp->comment);
			ft_putstr(") !\n");
			i++;
			tmp = tmp->next;
		}
	}
}

void	end_game(t_game *game)
{
	if (!(game->pcs) && game->verb == -1)
		graph_print_winner(game);
	else
	{
		if (game->dump == -1 && game->verb != -1)
			print_arena(game->arena, NB_OCTET_DISPLAY);
		if (!(game->pcs))
			print_winner(game);
		else if (game->verb != -1)
			print_arena(game->arena, NB_OCTET_DISPLAY);
	}
}

int		run(t_game *game)
{
	t_cycle	c;
	int		ret;

	init_cycle(&c);
	init_pc(game);
	present_player(game);
	game->nb_live = 0;
	if (game->verb == -1)
	{
		while (getch() != 32)
			;
	}
	while ((game->pcs != 0) &&
		(c.current <= game->dump || game->dump < 0))
	{
		print_cycle_current(game, c.current);
		if ((ret = run_pc(game, &c)) != 0)
			return (ret);
		(c.current)++;
		check_cycle(&c, game);
		if (game->verb == -1)
			display_end_cycle(game, &c);
	}
	end_game(game);
	return (0);
}
