/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_param_type_is.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:03:40 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 14:03:41 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdbool.h>

int			asm_is_numeric(const char *word)
{
	char	*ptr;

	ptr = (char *)word;
	if (*ptr == '-')
		ptr++;
	while (*ptr && ft_isdigit(*ptr))
		ptr++;
	if (ptr == word)
		return (false);
	if (asm_is_param_separator(*ptr) || ft_isspace(*ptr) || *ptr == '\0')
		return (true);
	return (false);
}

int			asm_is_param_label(const char *word)
{
	char	*ptr;

	if (*word == LABEL_CHAR)
	{
		word++;
		ptr = (char *)word;
		while (*ptr && asm_is_one_of_label_char(*ptr))
			ptr++;
		if (ptr == word)
			return (false);
		if (asm_is_param_separator(*ptr) || ft_isspace(*ptr) || *ptr == '\0')
			return (true);
	}
	return (false);
}

int			asm_param_is_register(const char *word)
{
	int		i;

	i = 0;
	if (*word == REGISTER_CHAR)
	{
		word++;
		while (word[i] && ft_isdigit(word[i]))
			i++;
		if (i != 0 && i <= REGISTER_LENGTH_MAX
				&& (asm_is_param_separator(word[i])
					|| ft_isspace(word[i]) || word[i] == '\0'))
			return (true);
	}
	return (false);
}
