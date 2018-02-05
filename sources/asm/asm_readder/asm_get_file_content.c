/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_file_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:34:48 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 10:34:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** asm_get_file_content
**
** Read the content of the file.
** Return EXIT_FAILURE on error, after outputing the error.
*/

int				asm_get_file_content(const char *filename, char **out_content)
{
	int			ret;

	ret = ft_read_file_with_filename(filename, out_content);
	if (ret == -1)
		return (error(INVALID_FILE, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
