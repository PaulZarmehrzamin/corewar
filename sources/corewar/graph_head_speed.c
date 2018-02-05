/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_head_speed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:52:36 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 17:33:05 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		set_speed(unsigned int speed, WINDOW *box)
{
	wattron(box, COLOR_PAIR(5));
	mvwprintw(box, POS_HEAD_INFO, POS_C_SPEED, "%d    ", speed);
	wattroff(box, COLOR_PAIR(5));
}
