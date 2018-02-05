/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:47:59 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 14:08:30 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		free_n_adn_val(t_argvparse *item)
{
	free_item_argvparse(item->next);
	free_item_argvparse(item);
	return (0);
}

static int		clear_in_begin(t_argvparse **argv)
{
	t_argvparse		*tmp;

	while ((*argv) && ft_strequ((*argv)->name, "-n"))
	{
		if (ft_isnum((*argv)->next->name) == 0)
			return (error(OPTNAV, -1));
		(*argv)->next->next->id = ft_atoi((*argv)->next->name);
		tmp = (*argv);
		(*argv) = (*argv)->next->next;
		free_n_adn_val(tmp);
	}
	return (0);
}

int				clear_n_option(t_argvparse **argv)
{
	t_argvparse		*tmp;
	t_argvparse		*begin;

	if (!(*argv) || !(*argv)->next || !(*argv)->next->next)
		return (0);
	if (clear_in_begin(argv) < 0)
		return (-1);
	begin = *argv;
	while (begin && begin->next && begin->next->next)
	{
		if (ft_strequ(begin->next->name, "-n"))
		{
			if (begin->next->next->next == NULL)
				return (0);
			if (ft_isnum(begin->next->next->name) == 0)
				return (error(OPTNAV, -1));
			begin->next->next->next->id = ft_atoi(begin->next->next->name);
			tmp = begin->next;
			begin->next = begin->next->next->next;
			free_n_adn_val(tmp);
		}
		else
			begin = begin->next;
	}
	return (0);
}
