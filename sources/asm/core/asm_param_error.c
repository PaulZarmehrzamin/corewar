/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_instruction_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:12:38 by mressier          #+#    #+#             */
/*   Updated: 2017/10/26 13:12:39 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

#define MESSAGE_SIZE_MAX		(1024 + INSTRUCT_LENGTH_MAX)

static void		internal_add_param_number(t_instruct *instruct, char *message)
{
	int			param_number;
	char		*nb;

	param_number = 0;
	while (instruct->param[param_number] != NULL)
		param_number++;
	nb = ft_itoa(param_number);
	ft_strcat(message, nb);
	free(nb);
}

static void		internal_add_param_details(t_instruct *instruct, char *message)
{
	internal_add_param_number(instruct, message);
	ft_strcat(message, " for instruction <");
	ft_strcat(message, instruct->name);
	ft_strcat(message, ">");
}

int				asm_param_error(t_instruct *instruct, const char *start_file,
					const char *error_ptr)
{
	char		message[MESSAGE_SIZE_MAX + 1];

	ft_bzero(message, MESSAGE_SIZE_MAX + 1);
	ft_strcpy(message, "Invalid parameter ");
	internal_add_param_details(instruct, message);
	asm_message_error(message, start_file, error_ptr);
	return (EXIT_FAILURE);
}
