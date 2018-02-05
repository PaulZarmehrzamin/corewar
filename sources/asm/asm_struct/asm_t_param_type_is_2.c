/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_param_type_is_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 09:32:26 by mressier          #+#    #+#             */
/*   Updated: 2017/10/27 09:32:27 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdbool.h>

int			asm_param_is_direct(const char *word)
{
	if (*word == DIRECT_CHAR)
	{
		word++;
		if (asm_is_numeric(word))
			return (true);
	}
	return (false);
}

int			asm_param_is_direct_label(const char *word)
{
	if (*word == DIRECT_CHAR)
	{
		word++;
		if (asm_is_param_label(word))
			return (true);
	}
	return (false);
}

int			asm_param_is_indirect(const char *word)
{
	if (asm_is_numeric(word))
		return (true);
	return (false);
}

int			asm_param_is_indirect_label(const char *word)
{
	if (asm_is_param_label(word))
		return (true);
	return (false);
}
