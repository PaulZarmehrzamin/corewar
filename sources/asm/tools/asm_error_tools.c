/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:15:06 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 11:15:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static int		internal_get_nb_line(const char *start, const char *ptr)
{
	return (ft_count_char_with_limit(start, ptr, '\n'));
}

static int		internal_get_nb_char(const char *start, const char *ptr)
{
	char	*prev_newline;
	int		size;

	size = 0;
	if (*ptr == '\n')
	{
		ptr--;
		size++;
	}
	prev_newline = ft_memrchr(start, ptr, '\n');
	if (prev_newline == NULL)
		size += (ptr - start) + 1;
	else
		size += ptr - prev_newline;
	return (size);
}

static char		*ft_strcat_nb(char *str, int nb)
{
	char	*temp;

	temp = ft_itoa(nb);
	str = ft_strcat(str, temp);
	free(temp);
	return (str);
}

void			asm_error_concat_line_and_char(const char *start,
					const char *ptr, char *str_error)
{
	int		nb_line;
	int		nb_char;

	if (!start || !ptr || !str_error)
	{
		ft_strcat(str_error, "\"[null]\"");
		return ;
	}
	nb_line = internal_get_nb_line(start, ptr);
	nb_char = internal_get_nb_char(start, ptr);
	ft_strcat(str_error, "[");
	ft_strcat_nb(str_error, nb_line + 1);
	ft_strcat(str_error, ",");
	ft_strcat_nb(str_error, nb_char);
	ft_strcat(str_error, "]");
}

void			asm_error_get_word_error(const char *error_ptr,
					char *word_error, int size_max)
{
	char	*end_error_ptr;
	int		size;

	end_error_ptr = ft_str_first(error_ptr, asm_is_param_separator);
	size = end_error_ptr - error_ptr;
	if (size > size_max)
	{
		size = size_max - 3;
		ft_strncpy(word_error, error_ptr, size);
		ft_strcat(word_error, "...");
		return ;
	}
	if (size > 0)
		ft_strncpy(word_error, error_ptr, size);
	else if (asm_is_param_separator(*end_error_ptr))
		ft_strncpy(word_error, error_ptr, 1);
	else
		ft_strcat(word_error, "(null)");
}
