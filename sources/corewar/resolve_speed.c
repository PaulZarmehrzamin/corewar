/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_speed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:51:46 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 14:36:40 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_if_good_speed(const char *value)
{
	int		val;

	val = 0;
	val = ft_atoi(value);
	if (val == 50 || val == 100 || val == 200 || val == 250 || val == 25 ||
		val == 1000)
		return (val);
	else
		return (-1);
}

static int		free_speed_and_val(t_argvparse *item)
{
	free_item_argvparse(item->next);
	free_item_argvparse(item);
	return (0);
}

static int		remove_first(t_argvparse **argv, int *speed)
{
	t_argvparse		*tmp;

	while ((*argv) && ft_strequ((*argv)->name, "-speed"))
	{
		if (ft_isnum((*argv)->next->name) == 0)
			return (error(SPEEDAV, -1));
		*speed = check_if_good_speed((*argv)->next->name);
		tmp = (*argv);
		(*argv) = (*argv)->next->next;
		free_speed_and_val(tmp);
	}
	return (0);
}

int				clear_speed_option(int *speed, t_argvparse **argv)
{
	t_argvparse		*tmp;
	t_argvparse		*begin;

	if (!(*argv) || !(*argv)->next)
		return (0);
	if (remove_first(argv, speed) < 0)
		return (-1);
	begin = *argv;
	while (begin && begin->next)
	{
		if (ft_strequ(begin->next->name, "-speed"))
		{
			if (begin->next->next == NULL)
				return (0);
			if (ft_isnum(begin->next->next->name) == 0)
				return (error(SPEEDAV, -1));
			*speed = check_if_good_speed(begin->next->next->name);
			tmp = begin->next;
			begin->next = begin->next->next->next;
			free_speed_and_val(tmp);
		}
		else
			begin = begin->next;
	}
	return (0);
}
