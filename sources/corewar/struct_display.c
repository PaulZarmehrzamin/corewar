/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:10:49 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/30 17:00:28 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_display	*init_display(void)
{
	t_display	*ret;

	ret = (t_display *)malloc(sizeof(t_display));
	if (ret == NULL)
		return (NULL);
	ret->box = subwin(stdscr, MAX_L, MAX_C, 0, 0);
	ret->head = subwin(stdscr, 4, MAX_C, 0, 0);
	return (ret);
}

void		release_display(t_display *display)
{
	if (display->head)
		free(display->head);
	if (display->box)
		free(display->box);
	free(display);
}
