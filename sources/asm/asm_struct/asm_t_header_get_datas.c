/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_header_get_datas.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:11:55 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 16:11:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static char		*internal_get_ptr_on_start(const char *file_content)
{
	return (ft_str_first_not(file_content, ft_isspace));
}

static char		*internal_get_ptr_on_end(const char *start)
{
	char	*end;

	end = (char *)start;
	while (*end != STRING_CHAR && *end != '\0')
		end++;
	return (end);
}

static int		internal_get_element_inside_quotes(t_parser *parser,
					size_t size_max, char *out_element)
{
	char	*start;
	char	*end;
	size_t	diff;

	ft_bzero(out_element, PROG_NAME_LENGTH + 1);
	start = internal_get_ptr_on_start(parser->current_ptr);
	if (!start || *start != STRING_CHAR)
		return (asm_message_error(SYNTAX_ERR, parser->file_content, start));
	start++;
	end = internal_get_ptr_on_end(start);
	if (!end || *end == '\0')
		return (asm_message_error(SYNTAX_ERR, parser->file_content, end));
	diff = end - start;
	if (diff > size_max)
		return (print_error(EXIT_FAILURE, "Name or comment too long"));
	ft_strncpy(out_element, start, diff);
	out_element[diff] = '\0';
	parser->current_ptr = asm_get_eol_or_next_instruct(end + 1);
	if (*(parser->current_ptr) != '\n')
	{
		return (asm_message_error(SYNTAX_ERR, parser->file_content,
			parser->current_ptr));
	}
	return (EXIT_SUCCESS);
}

int				asm_t_header_get_name(t_parser *parser, t_header *header)
{
	parser->current_ptr = ((char *)parser->current_ptr + NAME_CMD_STRING_SIZE);
	if (internal_get_element_inside_quotes(parser, PROG_NAME_LENGTH,
			header->prog_name) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				asm_t_header_get_comment(t_parser *parser, t_header *header)
{
	parser->current_ptr = (char *)parser->current_ptr
		+ COMMENT_CMD_STRING_SIZE;
	if (internal_get_element_inside_quotes(parser, COMMENT_LENGTH,
			header->comment) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
