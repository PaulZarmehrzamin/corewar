/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:51:56 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 19:25:48 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lib_error_one_ten(int id, int ret)
{
	if (id == INVALID_FILE)
		return (print_error(ret, "Can't read source file"));
	if (id == MALLOC_FAILED)
		return (print_error(ret, "Malloc() failed"));
	if (id == TOOSMALL)
		return (print_error(ret, "Terminal is too small for graphique"));
	return (ret);
}

int				system_error(int id, int ret)
{
	if (id <= (SYSTEM + 10))
		return (lib_error_one_ten(id, ret));
	return (ret);
}
