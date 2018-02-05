/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:33:34 by mplanell          #+#    #+#             */
/*   Updated: 2017/11/01 16:03:36 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

#define PARAM_SIZE		(PARAM_MAX * 4)

t_asm_instruct		*asm_t_asm_instruct_new(void)
{
	t_asm_instruct	*asm_instruct;

	asm_instruct = (t_asm_instruct *)ft_memalloc(sizeof(t_asm_instruct));
	ft_bzero(asm_instruct->param, PARAM_SIZE);
	asm_instruct->next = NULL;
	return (asm_instruct);
}

void				asm_t_asm_instruct_del(t_asm_instruct **instruct)
{
	if (instruct && *instruct)
		ft_memdel((void **)instruct);
}

void				asm_t_asm_instruct_del_list(t_asm_instruct *list)
{
	t_asm_instruct *ptr;

	if (list)
	{
		ptr = list;
		if (ptr->next)
			asm_t_asm_instruct_del_list(ptr->next);
		asm_t_asm_instruct_del(&list);
	}
}

void				asm_t_asm_instruct_add_to_end(t_asm_instruct **list,
						t_asm_instruct *add)
{
	if (!list || !add)
		return ;
	if (!(*list))
		*list = add;
	else
		asm_t_asm_instruct_add_to_end(&(*list)->next, add);
}
