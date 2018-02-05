/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:03:56 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/26 16:10:50 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			usage(void)
{
	ft_putstr_fd("[\033[32m USAGE \033[0m] \033[33m", 2);
	ft_putstr_fd("./corewar [-dump nbr_cycles] [-v 0-7] ", 2);
	ft_putstr_fd("[[-n number] champion] [-g] [-speed N]\n", 2);
	ft_putstr_fd("for verbosity level (-v N) :\n\t0 - show only ", 2);
	ft_putstr_fd("essential\n\t1 - show cycle and cycle to die", 2);
	ft_putstr_fd("\n\t2 - show process live and process kill", 2);
	ft_putstr_fd("\n\t4 - show AFF command\n", 2);
	ft_putstr_fd("for speed value (-speed N) :\n\t25 - cycle seconds ", 2);
	ft_putstr_fd("\n\t50 - cycle seconds", 2);
	ft_putstr_fd("\n\t100 - cycle seconds", 2);
	ft_putstr_fd("\n\t200 - cycle seconds", 2);
	ft_putstr_fd("\n\t250 - cycle seconds", 2);
	ft_putstr_fd("\n\t1000 - cycle seconds\n\033[0m", 2);
	return (-1);
}
