/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:49:33 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 11:49:34 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include <stdbool.h>

#define HANDLE_WORDS_TYPES 2

static int		internal_all_datas_are_get(int *header_datas_get)
{
	int		i;

	i = 0;
	while (i < HANDLE_WORDS_TYPES)
	{
		if (header_datas_get[i] == 0)
			return (false);
		i++;
	}
	return (true);
}

static int		internal_parse_header(t_parser *parser,
					t_header *header, int *header_datas_get)
{
	t_ft_parse_header	ft_parse[NB_WORD_TYPE];
	t_word_type			parse_mode;

	ft_parse[COMMAND_NAME] = asm_t_header_get_name;
	ft_parse[COMMAND_COMMENT] = asm_t_header_get_comment;
	parse_mode = asm_get_word_type(parser->current_ptr);
	if (parse_mode == INVALID_WORD_TYPE)
	{
		return (asm_message_error(LEXICAL_ERR, parser->file_content,
			parser->current_ptr));
	}
	if (parse_mode != COMMAND_NAME && parse_mode != COMMAND_COMMENT)
	{
		return (asm_message_error(SYNTAX_ERR, parser->file_content,
			parser->current_ptr));
	}
	if (header_datas_get[parse_mode] != 0)
	{
		return (asm_message_error(SYNTAX_ERR, parser->file_content,
			parser->current_ptr));
	}
	header_datas_get[parse_mode] = 1;
	return (ft_parse[parse_mode](parser, header));
}

int				asm_t_header_init_from_file(t_parser *parser,
					t_header *out_header)
{
	int		header_datas_get[HANDLE_WORDS_TYPES];

	parser->current_ptr = asm_skip_commented_lines(parser->current_ptr);
	parser->current_ptr = ft_str_first_not(parser->current_ptr, ft_isspace);
	ft_bzero(header_datas_get, sizeof(int) * HANDLE_WORDS_TYPES);
	while (internal_all_datas_are_get(header_datas_get) == false)
	{
		if (internal_parse_header(parser, out_header,
				header_datas_get) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		parser->current_ptr = asm_get_next_instruct(parser->current_ptr);
		if (parser->current_ptr == NULL)
		{
			asm_message_error(SYNTAX_ERR, parser->file_content,
				parser->current_ptr);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
