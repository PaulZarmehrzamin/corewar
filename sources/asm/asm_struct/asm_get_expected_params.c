/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_expected_param_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:31:06 by mressier          #+#    #+#             */
/*   Updated: 2017/10/26 14:31:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			init(int *to_set, int one,
						int two, int three)
{
	to_set[0] = one;
	to_set[1] = two;
	to_set[2] = three;
}

static void			init_t_instruct_expected_params(t_instruct_type type,
						int *params)
{
	if (type == INVALID_INSTRUCT || type > NB_INSTRUCT_TYPE)
		init(params, 0, 0, 0);
	if (type == LIVE || type == FORK || type == LFORK || type == ZJMP)
		init(params, T_DIR, 0, 0);
	if (type == LD)
		init(params, T_DIR | T_IND, T_REG, 0);
	if (type == ST)
		init(params, T_REG, T_IND | T_REG, 0);
	if (type == ADD || type == SUB)
		init(params, T_REG, T_REG, T_REG);
	if (type == AND || type == OR || type == XOR)
		init(params, T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG);
	if (type == LDI)
		init(params, T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG);
	if (type == STI)
		init(params, T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG);
	if (type == LLD)
		init(params, T_DIR | T_IND, T_REG, 0);
	if (type == LLDI)
		init(params, T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG);
	if (type == AFF)
		init(params, T_REG, 0, 0);
}

void				asm_get_expected_params(t_instruct_type type,
						int *params)
{
	init_t_instruct_expected_params(type, params);
}
