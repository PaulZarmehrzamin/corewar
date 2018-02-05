/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_next_instruct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:37:45 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 13:37:47 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** asm_get_next_instruction
**
** return a ptr on the next valid instruction on the file
** it search from the end of the current line
*/

char			*asm_get_next_instruct(const char *file_content)
{
	char	*ptr;

	if (!file_content || *file_content == '\0')
		return (NULL);
	ptr = ft_str_first_not(file_content, ft_isspace);
	if (ptr == file_content)
	{
		ptr = ft_strchr(file_content, '\n');
		if (ptr == NULL || *ptr == '\0')
			return (ptr);
	}
	ptr = asm_skip_commented_lines(ptr);
	if (ptr == NULL || *ptr == '\0')
		return (ptr);
	ptr = ft_str_first_not(ptr, ft_isspace);
	return (ptr);
}

char			*asm_get_eol_or_next_instruct(const char *string)
{
	char		*ptr;

	ptr = (char *)string;
	ptr = asm_skip_commented_lines(ptr);
	while (ptr && ft_isspace(*ptr) && *ptr != '\n')
		ptr++;
	return (ptr);
}
