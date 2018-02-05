/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:38:23 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 14:40:16 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			print_error(int ret, const char *message)
{
	char	error_mess[160];

	ft_bzero(error_mess, 160);
	ft_strcpy(error_mess, "[\033[31m ERROR \033[0m] \033[33m");
	ft_strcat(error_mess, message);
	ft_strcat(error_mess, ".\n\033[0m");
	ft_putstr_fd(error_mess, 2);
	return (ret);
}
