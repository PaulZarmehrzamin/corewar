/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_asm_word_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:41:36 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 10:41:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		internal_init_word_type_tab(t_asm_is *ft_asm_is)
{
	ft_asm_is[COMMAND_NAME] = asm_is_command_name;
	ft_asm_is[COMMAND_COMMENT] = asm_is_command_comment;
	ft_asm_is[LABEL] = asm_is_label;
	ft_asm_is[INSTRUCTION] = asm_is_instruction;
	ft_asm_is[SEPARATOR] = asm_is_separator;
	ft_asm_is[STRING] = asm_is_string;
	ft_asm_is[END_OF_LINE] = asm_is_end_of_line;
	ft_asm_is[END_OF_FILE] = asm_is_end_of_file;
	ft_asm_is[REG_PARAM_WORD] = asm_param_is_register;
	ft_asm_is[DIR_PARAM_WORD] = asm_param_is_direct;
	ft_asm_is[DIR_LABEL_PARAM_WORD] = asm_param_is_direct_label;
	ft_asm_is[INDIR_PARAM_WORD] = asm_param_is_indirect;
	ft_asm_is[INDIR_LABEL_PARAM_WORD] = asm_param_is_indirect_label;
}

t_word_type		asm_get_word_type(const char *word)
{
	t_asm_is			ft_asm_is[NB_WORD_TYPE];
	int					i;

	i = 0;
	internal_init_word_type_tab(ft_asm_is);
	while (i < NB_WORD_TYPE)
	{
		if (ft_asm_is[i](word))
			return (i);
		i++;
	}
	return (INVALID_WORD_TYPE);
}

char			*asm_t_word_type_to_string(t_word_type type)
{
	char			*words[NB_WORD_TYPE];

	if (type == INVALID_WORD_TYPE || type >= NB_WORD_TYPE)
		return ("unknow word type");
	words[COMMAND_NAME] = "COMMAND_NAME";
	words[COMMAND_COMMENT] = "COMMAND_COMMENT";
	words[LABEL] = "LABEL";
	words[INSTRUCTION] = "INSTRUCTION";
	words[SEPARATOR] = "SEPARATOR";
	words[STRING] = "STRING";
	words[END_OF_LINE] = "ENDLINE";
	words[END_OF_FILE] = "END";
	words[REG_PARAM_WORD] = "REGISTER";
	words[DIR_PARAM_WORD] = "DIRECT";
	words[DIR_LABEL_PARAM_WORD] = "DIRECT_LABEL";
	words[INDIR_PARAM_WORD] = "INDIRECT";
	words[INDIR_LABEL_PARAM_WORD] = "INDIRECT_LABEL";
	return (words[type]);
}
