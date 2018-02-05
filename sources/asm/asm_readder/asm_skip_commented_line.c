/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_line_is_comment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:56:38 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 11:56:42 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int			asm_line_is_comment(const char *line)
{
	char	*tmp;

	tmp = ft_str_first_not(line, ft_isspace);
	return (tmp && tmp[0] == COMMENT_CHAR);
}

/*
** asm_skip_commented_lines
**
** Return a pointer on the next line which is not a comment
** Should return the last \0 if the file end with a comment
*/

char		*asm_skip_commented_lines(const char *line)
{
	char		*next_line;
	char		*tmp;

	next_line = (char *)line;
	while (next_line && *next_line && asm_line_is_comment(next_line))
	{
		tmp = ft_strchr(next_line, '\n');
		if (tmp == NULL)
			tmp = ft_strchr(next_line, '\0');
		if (tmp == next_line)
			tmp = ft_str_first_not(next_line, ft_isspace);
		next_line = tmp;
	}
	return (next_line);
}
