/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_word_type_is.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:50:52 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 10:50:53 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdbool.h>

int				asm_is_command_name(const char *word)
{
	if (ft_strnequ(word, NAME_CMD_STRING, NAME_CMD_STRING_SIZE - 1))
		return (true);
	return (false);
}

int				asm_is_command_comment(const char *word)
{
	if (ft_strnequ(word, COMMENT_CMD_STRING, COMMENT_CMD_STRING_SIZE - 1))
		return (true);
	return (false);
}

int				asm_is_label(const char *word)
{
	char	*ptr;

	ptr = (char *)word;
	while (ptr && *ptr && asm_is_one_of_label_char(*ptr))
		ptr++;
	if (*ptr != LABEL_CHAR || ptr == word)
		return (false);
	return (true);
}

int				asm_is_instruction(const char *word)
{
	char	*ptr;

	ptr = (char *)word;
	while (ptr && *ptr && ft_isalpha(*ptr))
		ptr++;
	if (ft_isspace(*ptr) == false && *ptr != '\0' && *ptr != COMMENT_CHAR)
		return (false);
	if (ptr == word)
		return (false);
	return (true);
}

int				asm_is_end_of_file(const char *word)
{
	if (word && (*word == '\0' || ft_strequ(word, "(null)")))
		return (true);
	return (false);
}
