/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct_fill_param_tools.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:41:09 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/31 16:26:48 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

unsigned int	asm_t_asm_instruct_get_current_param_size(char *param,
					t_asm_instruct *asm_instruct)
{
	unsigned int	size;

	if (param[0] == '%')
	{
		if (asm_instruct->op_code == 1 || asm_instruct->op_code == 2 ||
				asm_instruct->op_code == 6 || asm_instruct->op_code == 7 ||
				asm_instruct->op_code == 8 || asm_instruct->op_code == 13)
			size = 4;
		else
			size = 2;
	}
	else
		size = 2;
	return (size);
}

void			asm_t_asm_instruct_convert_char_param_to_bytes(char *param,
					char *dest, int size)
{
	int		to_conv;

	if (*param == '%')
		param++;
	to_conv = ft_atoi(param);
	if (size == 4)
	{
		dest[0] = (to_conv >> 24) & 0xFF;
		dest[1] = (to_conv >> 16) & 0xFF;
		dest[2] = (to_conv >> 8) & 0xFF;
		dest[3] = to_conv & 0xFF;
	}
	else
	{
		dest[0] = (to_conv >> 8) & 0xFF;
		dest[1] = to_conv & 0xFF;
	}
}

void			asm_t_asm_instruct_convert_label_address_to_bytes(int param,
					char *dest, int size)
{
	if (size == 4)
	{
		dest[0] = (param >> 24) & 0xFF;
		dest[1] = (param >> 16) & 0xFF;
		dest[2] = (param >> 8) & 0xFF;
		dest[3] = param & 0xFF;
	}
	else
	{
		dest[0] = (param >> 8) & 0xFF;
		dest[1] = param & 0xFF;
	}
}

unsigned int	asm_t_asm_instruct_find_label(char *param, t_label *label_list)
{
	int		offset;

	offset = 1;
	if (param[1] == ':')
		offset = 2;
	while (label_list)
	{
		if (ft_strequ(param + offset, label_list->name))
			return (label_list->starting_byte);
		label_list = label_list->next;
	}
	return (-1);
}
