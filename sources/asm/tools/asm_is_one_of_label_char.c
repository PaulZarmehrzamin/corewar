/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_is_one_of_label_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:02:23 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 14:02:45 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "libft.h"
#include <stdbool.h>

int			asm_is_one_of_label_char(int c)
{
	if (c == '\0' || ft_strchr(LABEL_CHARS, c) == NULL)
		return (false);
	return (true);
}
