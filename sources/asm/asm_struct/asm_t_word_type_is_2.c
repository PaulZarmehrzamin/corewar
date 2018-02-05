/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_word_type_is_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:22:57 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 14:22:58 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdbool.h>

int			asm_is_separator(const char *word)
{
	if (*word == SEPARATOR_CHAR)
		return (true);
	return (false);
}

int			asm_is_end_of_line(const char *word)
{
	if (word && *word == '\n')
		return (true);
	return (false);
}

int			asm_is_string(const char *word)
{
	if (*word == STRING_CHAR)
		return (true);
	return (false);
}
