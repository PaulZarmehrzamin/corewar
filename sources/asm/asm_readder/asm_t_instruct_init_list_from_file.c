/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_instruct_init_from_file.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 09:27:47 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 09:27:48 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int			internal_get_instructs_for_label(t_parser *parser,
						t_label *label, t_label *label_list)
{
	t_word_type		word_type;

	while (parser->current_ptr && *parser->current_ptr)
	{
		word_type = asm_get_word_type(parser->current_ptr);
		if (word_type == INSTRUCTION)
		{
			if (asm_t_instruct_init_from_file(parser, label,
					label_list) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
			break ;
		parser->current_ptr = asm_get_next_instruct(parser->current_ptr);
	}
	return (EXIT_SUCCESS);
}

static int			internal_return_word_error(t_word_type wt, t_parser *prs)
{
	return (asm_word_type_error(wt, prs->file_content, prs->current_ptr));
}

int					asm_t_instruct_init_list_from_file(t_parser *parser,
						t_label *label_list)
{
	t_word_type		word_type;
	t_label			*ptr;

	ptr = NULL;
	while (parser->current_ptr && *parser->current_ptr)
	{
		word_type = asm_get_word_type(parser->current_ptr);
		if (word_type == LABEL)
		{
			if ((ptr = (ptr == NULL) ? label_list : ptr->next) == NULL)
				return (print_error(EXIT_FAILURE, "Caca dans les labels!!"));
			asm_file_skip_label(parser);
		}
		else if (word_type == INSTRUCTION)
		{
			if (ptr == NULL)
				ptr = label_list;
			if (internal_get_instructs_for_label(parser, ptr,
					label_list) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
			return (internal_return_word_error(word_type, parser));
	}
	return (EXIT_SUCCESS);
}
