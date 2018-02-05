/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:51:34 by mressier          #+#    #+#             */
/*   Updated: 2017/10/31 17:56:35 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int		internal_check_arg_number(int ac)
{
	if (ac < 2)
	{
		return (print_error(EXIT_FAILURE,
			"Bad number of arguments (need at least one file)"));
	}
	return (EXIT_SUCCESS);
}

static int		internal_get_filename_on_arg(int ac, char **av, int i,
					char **out_filename)
{
	char	*ptr;

	*out_filename = NULL;
	if (i >= ac)
		return (EXIT_SUCCESS);
	ptr = ft_strrchr(av[i], '.');
	if (ptr == NULL || *(ptr + 1) != 's' || *(ptr + 2) != '\0')
	{
		return (print_error(EXIT_FAILURE,
			"Bad extension for filename (should be .s)"));
	}
	*out_filename = av[i];
	return (EXIT_SUCCESS);
}

static int		internal_create_asm_file(char *filename)
{
	char		*file_content;
	t_asm		asm_file_content;

	asm_t_asm_init(&asm_file_content);
	if (asm_get_file_content(filename, &file_content) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (asm_get_asm_from_file_content(file_content,
			&asm_file_content) == EXIT_FAILURE)
	{
		ft_memdel((void **)&file_content);
		asm_t_asm_del_content(asm_file_content);
		return (EXIT_FAILURE);
	}
	asm_t_asm_instruct_init_list(&asm_file_content);
	if (asm_write_asm_to_file(&asm_file_content, filename) == EXIT_FAILURE)
	{
		ft_memdel((void **)&file_content);
		asm_t_asm_del_content(asm_file_content);
		return (EXIT_FAILURE);
	}
	asm_t_asm_del_content(asm_file_content);
	ft_memdel((void **)&file_content);
	return (EXIT_SUCCESS);
}

int				main(int ac, char **av)
{
	char		*filename;
	int			i;
	int			exit_status;

	exit_status = EXIT_SUCCESS;
	if (internal_check_arg_number(ac) == EXIT_FAILURE)
		return (asm_usage());
	i = 1;
	while (i < ac)
	{
		if (internal_get_filename_on_arg(ac, av, i, &filename) == EXIT_FAILURE
				|| filename == NULL)
			return (asm_usage());
		if (ac > 2)
		{
			ft_putstr(filename);
			ft_putendl(":");
		}
		if (internal_create_asm_file(filename) == EXIT_FAILURE)
			exit_status = EXIT_FAILURE;
		else
			ft_putendl("\033[32mbinary file has been created\033[0m");
		i++;
	}
	return (exit_status);
}
