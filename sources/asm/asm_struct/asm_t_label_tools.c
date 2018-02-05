/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_label_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:47:40 by mressier          #+#    #+#             */
/*   Updated: 2017/10/27 11:47:41 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdbool.h>

int			asm_is_label_name_equal(t_label *label, void *data)
{
	char	*name;

	name = data;
	if (label && ft_strequ(label->name, name))
		return (true);
	return (false);
}

t_label		*asm_t_label_find(t_label *list, void *data, t_asm_label_cmp find)
{
	t_label		*ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (find(ptr, data) == true)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}
