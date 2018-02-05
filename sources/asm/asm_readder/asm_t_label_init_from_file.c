/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_label_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:14:52 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 14:14:54 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int			internal_set_label_name(t_parser *parser,
						t_label *new_label)
{
	char			*name_end;
	int				label_size;

	name_end = ft_str_first_not(parser->current_ptr, asm_is_one_of_label_char);
	if (*name_end != LABEL_CHAR || name_end == parser->current_ptr)
	{
		return (asm_message_error(LEXICAL_ERR, parser->file_content,
			name_end));
	}
	label_size = name_end - parser->current_ptr;
	if (label_size >= LABEL_LENGTH_MAX)
		return (print_error(EXIT_FAILURE, "Label name too long (max 128)"));
	ft_strncpy(new_label->name, parser->current_ptr, label_size);
	return (EXIT_SUCCESS);
}

static int			internal_init_and_add_one_label(t_parser *parser,
						t_label **list)
{
	t_label			*new_label;

	new_label = asm_t_label_new();
	*list = asm_t_label_add_end(*list, new_label);
	if (internal_set_label_name(parser, new_label) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int			internal_return_word_error(t_word_type wt, t_parser *prs)
{
	return (asm_word_type_error(wt, prs->file_content, prs->current_ptr));
}

static int			internal_get_all_labels_on_file(t_parser *parser,
						t_label **list_to_set)
{
	t_word_type		word_type;

	while (parser->current_ptr && *parser->current_ptr)
	{
		word_type = asm_get_word_type(parser->current_ptr);
		if (word_type == LABEL)
		{
			if (internal_init_and_add_one_label(parser,
					list_to_set) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			asm_file_skip_label(parser);
		}
		else if (word_type == INSTRUCTION)
		{
			if (*list_to_set == NULL)
				*list_to_set = asm_t_label_add_end(*list_to_set,
					asm_t_label_new());
			parser->current_ptr = asm_get_next_instruct(parser->current_ptr);
		}
		else
			return (internal_return_word_error(word_type, parser));
	}
	return (EXIT_SUCCESS);
}

int					asm_t_label_init_from_file(t_parser *parser,
						t_label **list_to_set)
{
	if (internal_get_all_labels_on_file(parser, list_to_set) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
