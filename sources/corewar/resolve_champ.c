/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:16:58 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/24 16:54:33 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		bad_name(const char *name, int ret)
{
	char		error[256];

	if (ft_strlen(name) > 160)
		return (ret);
	ft_strcpy(error, "ARGUMENT : ");
	ft_strcat(error, name);
	ft_strcat(error, " is not a champion...");
	return (print_error(ret, error));
}

static int		is_champ(const char *name)
{
	char		**tmp;
	int			ret;

	tmp = ft_strsplit(name, '.');
	if (tmp == NULL)
		return (-1);
	ret = ft_len_tab(tmp);
	if (ret < 2)
	{
		ft_memtabdel((void *)&tmp);
		return (-1);
	}
	if (ft_strequ(tmp[ret - 1], "cor"))
	{
		ft_memtabdel((void *)&tmp);
		return (1);
	}
	ft_memtabdel((void *)&tmp);
	return (-1);
}

static void		attrib_id_number(int *id, t_argvparse *item, t_argvparse *list)
{
	while (check_if_id_use(*id, list))
		*id = *id - 1;
	item->id = *id;
}

int				check_is_correct_champ(t_argvparse *argv, t_game *game)
{
	t_argvparse *begin;
	int			nb;
	int			id;

	id = -1;
	begin = argv;
	nb = 0;
	while (begin)
	{
		if (is_champ(begin->name) < 0)
			return (bad_name(begin->name, -1));
		if (begin->id == -999)
			attrib_id_number(&id, begin, argv);
		game->winner = begin->id;
		begin = begin->next;
		nb++;
	}
	game->nb_pc = nb;
	if (nb > MAX_PLAYERS)
		return (error(TOO_MANY_CHAMP, -1));
	if (nb == 0)
		return (error(NO_CHAMP, -1));
	return (0);
}
