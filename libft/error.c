/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:25:04 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 18:34:23 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				error(int id, int ret)
{
	if (id > SYNTAX && id < SYSTEM)
		return (syntax_error(id, ret));
	if (id > SYSTEM)
		return (system_error(id, ret));
	return (ret);
}
