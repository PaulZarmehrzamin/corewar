/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:10:38 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 18:10:39 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void			asm_file_skip_label(t_parser *parser)
{
	parser->current_ptr = ft_str_first_not(parser->current_ptr,
		asm_is_one_of_label_char);
	parser->current_ptr++;
	parser->current_ptr = asm_get_eol_or_next_instruct(parser->current_ptr);
	parser->current_ptr = ft_str_first_not(parser->current_ptr, ft_isspace);
}

int				asm_is_param_separator(int c)
{
	return (ft_isspace(c) || c == SEPARATOR_CHAR || c == COMMENT_CHAR);
}
