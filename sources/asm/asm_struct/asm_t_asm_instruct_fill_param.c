/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct_fill_param.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:54:55 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/31 16:24:42 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int		internal_asm_convert_register(char *param,
					t_asm_instruct *asm_instruct, int pos)
{
	char	reg;

	reg = (char)ft_atoi(param + 1);
	asm_instruct->param[pos] = reg;
	return (1);
}

static int		internal_asm_convert_dir(char *param,
					t_asm_instruct *asm_instruct, int pos)
{
	unsigned int	size;

	size = asm_t_asm_instruct_get_current_param_size(param, asm_instruct);
	asm_t_asm_instruct_convert_char_param_to_bytes(param,
		asm_instruct->param + pos, size);
	return (size);
}

static int		internal_asm_convert_ind(char *param,
					t_asm_instruct *asm_instruct, int pos)
{
	asm_t_asm_instruct_convert_char_param_to_bytes(param,
		asm_instruct->param + pos, 2);
	return (2);
}

static int		internal_asm_convert_label(char *param,
					t_asm_instruct *asm_instruct, int pos, t_label *label_list)
{
	unsigned int	label_starting_byte;
	unsigned int	size;

	label_starting_byte = asm_t_asm_instruct_find_label(param, label_list);
	size = asm_t_asm_instruct_get_current_param_size(param, asm_instruct);
	asm_t_asm_instruct_convert_label_address_to_bytes(label_starting_byte -
			asm_instruct->starting_byte, asm_instruct->param + pos, size);
	return (2);
}

void			asm_t_asm_instruct_fill_param(t_asm_instruct *asm_instruct,
					t_instruct *target, t_label *label_list)
{
	int		i;
	int		type;
	int		pos;

	i = 0;
	pos = 0;
	while (target->param[i] && i < PARAM_MAX)
	{
		type = asm_t_asm_instruct_identify_param_type(target->param[i]);
		if (type == T_REG)
			pos += internal_asm_convert_register(target->param[i],
				asm_instruct, pos);
		if (type == T_DIR)
			pos += internal_asm_convert_dir(target->param[i],
				asm_instruct, pos);
		if (type == T_IND)
			pos += internal_asm_convert_ind(target->param[i],
				asm_instruct, pos);
		if (type == (T_DIR | T_LAB) || type == (T_IND | T_LAB))
			pos += internal_asm_convert_label(target->param[i],
				asm_instruct, pos, label_list);
		i++;
	}
}
