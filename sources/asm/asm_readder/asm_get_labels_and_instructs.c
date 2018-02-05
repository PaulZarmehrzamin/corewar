/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_label_and_instructs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 09:22:43 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 09:22:45 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int			asm_get_labels_and_instructs(t_parser *parser,
						t_label **list_to_set)
{
	char		*ptr_on_file_start;

	ptr_on_file_start = parser->current_ptr;
	if (asm_t_label_init_from_file(parser, list_to_set) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	parser->current_ptr = ptr_on_file_start;
	if (asm_t_instruct_init_list_from_file(parser,
			*list_to_set) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
