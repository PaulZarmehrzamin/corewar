/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:04:14 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/29 14:58:22 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					print_argv(t_argvparse *argv)
{
	while (argv)
	{
		ft_putstr(argv->name);
		ft_putnbr(argv->id);
		ft_putendl(" ");
		argv = argv->next;
	}
}

void					print_register(int *reg)
{
	int		index;

	index = 0;
	while (index < REG_NUMBER)
	{
		ft_putstr("\nRegistre ");
		ft_putnbr(index + 1);
		ft_putstr(" => ");
		ft_putnbr(reg[index]);
		index++;
	}
}

void					print_pcs_list(t_pc *pcs)
{
	while (pcs)
	{
		ft_putendl("New pcs");
		ft_putstr("addr : ");
		ft_putnbr(pcs->addr);
		ft_putstr("\nregistre : ");
		print_register(pcs->reg);
		ft_putstr("\ncarry : ");
		ft_putnbr(pcs->carry);
		ft_putstr("\nlast_live : ");
		ft_putnbr(pcs->last_live);
		ft_putstr("\nwait : ");
		ft_putnbr(pcs->wait);
		ft_putstr("\nid player : ");
		ft_putnbr(pcs->id_player);
		ft_putendl(".");
		pcs = pcs->next;
	}
}

void					print_players_list(t_player *player)
{
	while (player)
	{
		ft_putendl("New Players");
		ft_putendl(player->name);
		ft_putendl(player->comment);
		ft_putstr("live : ");
		ft_putnbr(player->live);
		ft_putendl(".");
		ft_putendl("End Players");
		player = player->next;
	}
}

void					print_game(t_game *game)
{
	print_players_list(game->players);
	print_pcs_list(game->pcs);
	ft_putstr("Dump : ");
	ft_putnbr(game->dump);
	ft_putstr("\nverb : ");
	ft_putnbr(game->verb);
	ft_putstr("\nwinner : ");
	ft_putnbr(game->winner);
	ft_putendl(".");
}
