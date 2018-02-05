/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_asm_from_file_content.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:02:42 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 11:02:43 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int			asm_get_asm_from_file_content(const char *file, t_asm *asm_content)
{
	t_parser	parser;

	parser.file_content = (char *)file;
	parser.current_ptr = parser.file_content;
	if (asm_t_header_init_from_file(&parser,
			&(asm_content->header)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (asm_get_labels_and_instructs(&parser,
			&(asm_content->label_list)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
