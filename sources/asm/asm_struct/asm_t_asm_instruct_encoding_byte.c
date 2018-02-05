/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct_encoding_byte.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:45:29 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/31 17:34:50 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				asm_t_asm_instruct_identify_param_type(char *param)
{
	if (param[0] == 'r')
		return (T_REG);
	if (param[0] == '%' && param[1] == ':')
		return (T_DIR | T_LAB);
	if (param[0] == '%')
		return (T_DIR);
	if (param[0] == ':')
		return (T_IND | T_LAB);
	else
		return (T_IND);
}

static int		internal_asm_param_type(char *param)
{
	if (param[0] == 'r')
		return (REG_CODE);
	if (param[0] == '%')
		return (DIR_CODE);
	else
		return (IND_CODE);
}

char			asm_t_asm_instruct_get_param_code(char **params)
{
	char	param_code;

	param_code = internal_asm_param_type(params[0]) << 6;
	if (params[1])
		param_code += internal_asm_param_type(params[1]) << 4;
	if (params[2])
		param_code += internal_asm_param_type(params[2]) << 2;
	return (param_code);
}
