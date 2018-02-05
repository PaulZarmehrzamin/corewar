/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:15:06 by mressier          #+#    #+#             */
/*   Updated: 2017/10/29 17:28:28 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_label				*asm_t_label_new(void)
{
	t_label		*new_label;

	new_label = (t_label *)ft_memalloc(sizeof(t_label));
	ft_bzero(new_label->name, LABEL_LENGTH_MAX + 1);
	new_label->instruct_list = NULL;
	new_label->asm_instruct_list = NULL;
	new_label->next = NULL;
	return (new_label);
}

void				asm_t_label_del(t_label **label)
{
	t_label		*ptr;

	if (label && *label)
	{
		ptr = *label;
		asm_t_instruct_del_list(ptr->instruct_list);
		ptr->instruct_list = NULL;
		asm_t_asm_instruct_del_list(ptr->asm_instruct_list);
		ptr->asm_instruct_list = NULL;
		ft_memdel((void **)label);
	}
}

void				asm_t_label_del_list(t_label *list)
{
	t_label		*ptr;

	if (list)
	{
		ptr = list;
		if (ptr->next)
			asm_t_label_del_list(ptr->next);
		asm_t_label_del(&list);
	}
}

t_label				*asm_t_label_add_end(t_label *list, t_label *add)
{
	t_label	*ptr;

	ptr = list;
	if (ptr == NULL)
		return (add);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = add;
	return (list);
}

void				asm_t_label_display_list(t_label *list)
{
	t_label		*ptr;
	int			i;

	i = 0;
	ptr = list;
	while (ptr)
	{
		ft_putstr("label (");
		ft_putnbr(i);
		ft_putstr(") : ");
		ft_putstr(ptr->name);
		ft_putstr(" (");
		ft_putnbr(ptr->starting_byte);
		ft_putendl(")");
		asm_t_instruct_display_list(ptr->instruct_list, 1);
		ptr = ptr->next;
		i++;
	}
}
