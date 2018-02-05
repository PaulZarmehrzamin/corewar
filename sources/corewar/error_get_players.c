/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_get_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:48:49 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 16:50:48 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_game			*exit_error_get_player(int id, t_game *game, t_argvparse *argv)
{
	error(id, 0);
	release_game(game);
	release_argvparse(&argv);
	return (NULL);
}
