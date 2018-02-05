/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_instruct_init_from_file.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 10:28:44 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 10:28:45 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int			internal_init_instruct_name(t_parser *parser,
						t_instruct *instruct)
{
	char			*ptr;
	int				name_size;

	ptr = ft_str_first_not(parser->current_ptr, ft_isalpha);
	if (!ft_isspace(*ptr))
		return (asm_message_error(SYNTAX_ERR, parser->file_content, ptr));
	name_size = ptr - parser->current_ptr;
	if (name_size > INSTRUCT_LENGTH_MAX)
	{
		return (asm_message_error("Invalid instruction at",
			parser->file_content, parser->current_ptr));
	}
	ft_strncpy(instruct->name, parser->current_ptr, name_size);
	if (asm_get_instruct_type(instruct->name) == INVALID_INSTRUCT)
	{
		return (asm_message_error("Invalid instruction at",
			parser->file_content, parser->current_ptr));
	}
	parser->current_ptr = ptr;
	return (EXIT_SUCCESS);
}

static int			internal_init_instruct_params(t_parser *parser,
						t_instruct *instruct, t_label *label_list)
{
	while (parser->current_ptr && *parser->current_ptr)
	{
		parser->current_ptr = asm_get_eol_or_next_instruct(parser->current_ptr);
		if (!parser->current_ptr || *parser->current_ptr == '\n'
				|| *parser->current_ptr == '\0')
			break ;
		if (asm_t_instruct_param_init_from_file(parser,
				instruct, label_list) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (asm_t_instruct_param_number_is_valid(parser, instruct));
}

int					asm_t_instruct_init_from_file(t_parser *parser,
						t_label *label, t_label *label_list)
{
	t_instruct		*new_instruct;

	new_instruct = asm_t_instruct_new();
	label->instruct_list = asm_t_instruct_add_end(label->instruct_list,
		new_instruct);
	if (internal_init_instruct_name(parser, new_instruct) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (internal_init_instruct_params(parser, new_instruct,
			label_list) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
