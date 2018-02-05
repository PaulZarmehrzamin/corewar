/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct_byte_count.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 02:53:23 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/29 14:50:06 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	asm_t_asm_instruct_get_param_size(t_asm_instruct *asm_instruct,
					t_instruct *target, int size)
{
	unsigned int	param_size;
	unsigned int	type;
	unsigned int	i;

	i = 0;
	param_size = 0;
	while (target->param[i] && i < PARAM_MAX)
	{
		type = asm_t_asm_instruct_identify_param_type(target->param[i]);
		if (type == T_REG)
			param_size += 1;
		if (type == T_DIR)
			param_size += size;
		if (type == T_IND)
			param_size += 2;
		if (type == (T_DIR | T_LAB) || type == (T_IND | T_LAB))
			param_size += 2;
		i++;
	}
	asm_instruct->param_size = param_size;
}

void	asm_t_asm_instruct_byte_and_param_count(t_asm_instruct *asm_instruct,
					t_instruct *target)
{
	if (asm_instruct->param_code == 0)
		asm_instruct->byte_count = 1;
	else
		asm_instruct->byte_count = 2;
	if (asm_instruct->op_code == 1 || asm_instruct->op_code == 2 ||
			asm_instruct->op_code == 6 || asm_instruct->op_code == 7 ||
			asm_instruct->op_code == 8 || asm_instruct->op_code == 13)
		asm_t_asm_instruct_get_param_size(asm_instruct, target, 4);
	else if (asm_instruct->op_code == 9 || asm_instruct->op_code == 10 ||
			asm_instruct->op_code == 11 || asm_instruct->op_code == 12 ||
			asm_instruct->op_code == 14 || asm_instruct->op_code == 15)
		asm_t_asm_instruct_get_param_size(asm_instruct, target, 2);
	else
		asm_t_asm_instruct_get_param_size(asm_instruct, target, 0);
	asm_instruct->byte_count += asm_instruct->param_size;
}
