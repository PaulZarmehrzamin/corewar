/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:08:51 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 18:47:02 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	if_first(t_argvparse **argv, int *graph)
{
	t_argvparse		*tmp;

	while ((*argv) && ft_strequ((*argv)->name, "-g"))
	{
		*graph = -1;
		tmp = (*argv);
		(*argv) = (*argv)->next;
		free_item_argvparse(tmp);
	}
	return (0);
}

int			clear_graph_option(int *graph, t_argvparse **argv)
{
	t_argvparse		*tmp;
	t_argvparse		*begin;

	if (!(*argv) || !(*argv)->next)
		return (0);
	if (if_first(argv, graph) < 0)
		return (-1);
	begin = *argv;
	while (begin && begin->next)
	{
		if (ft_strequ(begin->next->name, "-g"))
		{
			*graph = -1;
			tmp = begin->next;
			begin->next = begin->next->next;
			free_item_argvparse(tmp);
		}
		else
			begin = begin->next;
	}
	return (0);
}
