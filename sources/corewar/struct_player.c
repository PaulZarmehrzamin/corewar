/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:11:24 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/29 14:55:05 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					count_my_player(t_player *player)
{
	t_player	*begin;
	int			ret;

	ret = 0;
	begin = player;
	while (begin)
	{
		ret++;
		begin = begin->next;
	}
	return (ret);
}

static void			free_item_player(t_player *player)
{
	ft_memdel((void *)&player);
}

void				release_player(t_player **player)
{
	if (!player || !*player)
		return ;
	release_player(&((*player)->next));
	free_item_player(*player);
}

void				add_in_player_list(t_player **player,
												t_player *to_add)
{
	t_player *begin;

	if (!player || !to_add)
		return ;
	else if (!*player)
		*player = to_add;
	else
	{
		begin = *player;
		while (begin->next)
			begin = begin->next;
		begin->next = to_add;
	}
}

t_player			*new_player(void)
{
	t_player	*ret;

	ret = (t_player *)malloc(sizeof(t_player));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret->name, PROG_NAME_LENGTH + 1);
	ft_bzero(ret->comment, COMMENT_LENGTH + 1);
	ret->live = 0;
	ret->next = NULL;
	return (ret);
}
