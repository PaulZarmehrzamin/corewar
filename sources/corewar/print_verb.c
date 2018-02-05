/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_verb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:24:26 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/30 16:38:04 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_cycle_current(t_game *game, int current)
{
	if (game->verb & 1 && game->verb != -1)
	{
		ft_putstr("It is now cycle ");
		ft_putnbr(current);
		ft_putstr(".\n");
	}
}

void	print_cycle_to_die(t_game *game, int to_die)
{
	if (game->verb & 1 && game->verb != -1)
	{
		ft_putstr("Cycle to die is now ");
		ft_putnbr(to_die);
		ft_putstr(".\n");
	}
}

void	print_pc_live(t_game *game, int live)
{
	if (game->verb & 2 && game->verb != -1)
	{
		ft_putstr("A process is alive (live %");
		ft_putnbr(live);
		ft_putstr(").\n");
	}
}

void	print_pc_kill(t_game *game)
{
	if (game->verb & 2 && game->verb != -1)
	{
		ft_putstr("A process has been killed.\n");
	}
}

void	print_aff(t_game *game, int c)
{
	if (game->verb & 4 && game->verb != -1)
	{
		ft_putstr("AFF : '");
		ft_putchar(c);
		ft_putstr("'\n");
	}
}
