/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_instruct_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:01:56 by mressier          #+#    #+#             */
/*   Updated: 2017/10/26 14:01:58 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static void			init_t_instruct_type_strings(char **instruct_types)
{
	instruct_types[LIVE] = "live";
	instruct_types[LD] = "ld";
	instruct_types[ST] = "st";
	instruct_types[ADD] = "add";
	instruct_types[SUB] = "sub";
	instruct_types[AND] = "and";
	instruct_types[OR] = "or";
	instruct_types[XOR] = "xor";
	instruct_types[ZJMP] = "zjmp";
	instruct_types[LDI] = "ldi";
	instruct_types[STI] = "sti";
	instruct_types[FORK] = "fork";
	instruct_types[LLD] = "lld";
	instruct_types[LLDI] = "lldi";
	instruct_types[LFORK] = "lfork";
	instruct_types[AFF] = "aff";
}

t_instruct_type		asm_get_instruct_type(const char *word)
{
	char		*instruct_types[NB_INSTRUCT_TYPE];
	int			i;

	i = 0;
	init_t_instruct_type_strings(instruct_types);
	while (i < NB_INSTRUCT_TYPE)
	{
		if (ft_strequ(word, instruct_types[i]))
			return (i);
		i++;
	}
	return (INVALID_INSTRUCT);
}

char				*asm_t_instruct_type_to_string(t_instruct_type type)
{
	char		*instruct_types[NB_INSTRUCT_TYPE];

	if (type == INVALID_INSTRUCT || type >= NB_INSTRUCT_TYPE)
		return ("unknow instruction type");
	init_t_instruct_type_strings(instruct_types);
	return (instruct_types[type]);
}
