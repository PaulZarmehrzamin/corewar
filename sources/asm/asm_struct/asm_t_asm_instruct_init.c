/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:07:57 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/31 17:37:55 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static void		internal_asm_t_asm_instruct_get_op_code_2(t_asm_instruct
					*asm_instruct, t_instruct *target)
{
	if (ft_strequ("lld", target->name))
		asm_instruct->op_code = 13;
	if (ft_strequ("lldi", target->name))
		asm_instruct->op_code = 14;
	if (ft_strequ("lfork", target->name))
		asm_instruct->op_code = 15;
	if (ft_strequ("aff", target->name))
		asm_instruct->op_code = 16;
}

static void		internal_asm_t_asm_instruct_get_op_code(t_asm_instruct
					*asm_instruct, t_instruct *target)
{
	if (ft_strequ("live", target->name))
		asm_instruct->op_code = 1;
	if (ft_strequ("ld", target->name))
		asm_instruct->op_code = 2;
	if (ft_strequ("st", target->name))
		asm_instruct->op_code = 3;
	if (ft_strequ("add", target->name))
		asm_instruct->op_code = 4;
	if (ft_strequ("sub", target->name))
		asm_instruct->op_code = 5;
	if (ft_strequ("and", target->name))
		asm_instruct->op_code = 6;
	if (ft_strequ("or", target->name))
		asm_instruct->op_code = 7;
	if (ft_strequ("xor", target->name))
		asm_instruct->op_code = 8;
	if (ft_strequ("zjmp", target->name))
		asm_instruct->op_code = 9;
	if (ft_strequ("ldi", target->name))
		asm_instruct->op_code = 10;
	if (ft_strequ("sti", target->name))
		asm_instruct->op_code = 11;
	if (ft_strequ("fork", target->name))
		asm_instruct->op_code = 12;
	internal_asm_t_asm_instruct_get_op_code_2(asm_instruct, target);
}

void			asm_t_asm_instruct_init_params(t_asm *asm_file_content)
{
	t_label				*label;
	t_instruct			*instruct;
	t_asm_instruct		*asm_instruct;

	label = asm_file_content->label_list;
	while (label)
	{
		instruct = label->instruct_list;
		asm_instruct = label->asm_instruct_list;
		while (instruct)
		{
			asm_t_asm_instruct_fill_param(asm_instruct, instruct,
				asm_file_content->label_list);
			instruct = instruct->next;
			asm_instruct = asm_instruct->next;
		}
		label = label->next;
	}
}

void			asm_t_asm_instruct_init(t_asm_instruct *asm_instruct,
			t_instruct *target, unsigned int current_byte)
{
	internal_asm_t_asm_instruct_get_op_code(asm_instruct, target);
	if (asm_instruct->op_code == 1 || asm_instruct->op_code == 9 ||
			asm_instruct->op_code == 12 || asm_instruct->op_code == 15)
		asm_instruct->param_code = 0;
	else
		asm_instruct->param_code =
			asm_t_asm_instruct_get_param_code(target->param);
	asm_instruct->starting_byte = current_byte;
}

void			asm_t_asm_instruct_init_list(t_asm *asm_file_content)
{
	t_label				*label;
	t_instruct			*instruct;
	t_asm_instruct		*asm_instruct;
	unsigned int		current_byte;

	label = asm_file_content->label_list;
	current_byte = 0;
	while (label)
	{
		label->starting_byte = current_byte;
		instruct = label->instruct_list;
		while (instruct)
		{
			asm_instruct = asm_t_asm_instruct_new();
			asm_t_asm_instruct_init(asm_instruct, instruct, current_byte);
			asm_t_asm_instruct_byte_and_param_count(asm_instruct, instruct);
			asm_t_asm_instruct_add_to_end(&label->asm_instruct_list,
				asm_instruct);
			current_byte += asm_instruct->byte_count;
			instruct = instruct->next;
		}
		label = label->next;
	}
	asm_file_content->header.prog_size = current_byte;
	asm_t_asm_instruct_init_params(asm_file_content);
}
