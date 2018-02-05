/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:59:02 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/24 17:43:27 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			free_item_pcs(t_pc *pcs)
{
	ft_memdel((void *)&pcs);
}

void				release_pcs(t_pc **pcs)
{
	if (!pcs || !*pcs)
		return ;
	release_pcs(&((*pcs)->next));
	free_item_pcs(*pcs);
}

void				push_in_front_pc(t_pc **pcs, t_pc *add)
{
	if (!*pcs || !pcs)
		*pcs = add;
	else
	{
		add->next = (*pcs);
		*pcs = add;
	}
}

static void			init_register(int *reg, int live)
{
	int			index;

	index = 1;
	reg[0] = live;
	while (index < REG_NUMBER)
	{
		reg[index] = 0;
		index++;
	}
}

t_pc				*new_pc(int live)
{
	t_pc		*ret;

	ret = (t_pc *)malloc(sizeof(t_pc));
	if (ret == NULL)
		return (NULL);
	ret->wait = 0;
	ret->addr = 0;
	ret->last_live = 0;
	ret->carry = 0;
	ret->cmd = NULL;
	init_register(ret->reg, live);
	ret->next = NULL;
	return (ret);
}
