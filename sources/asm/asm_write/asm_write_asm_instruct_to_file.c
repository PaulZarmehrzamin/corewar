/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_asm_instruct_to_file.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:04:53 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/29 14:47:01 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_write_t_asm_instruct_to_file(t_asm_instruct *instruct, int fd)
{
	write(fd, &instruct->op_code, 1);
	if (instruct->param_code != 0)
		write(fd, &instruct->param_code, 1);
	write(fd, &instruct->param, instruct->param_size);
}

void	asm_write_t_asm_instruct_list_to_file(t_label *label, int fd)
{
	t_label			*label_ptr;
	t_asm_instruct	*current;

	label_ptr = label;
	while (label_ptr)
	{
		current = label_ptr->asm_instruct_list;
		while (current)
		{
			asm_write_t_asm_instruct_to_file(current, fd);
			current = current->next;
		}
		label_ptr = label_ptr->next;
	}
}
