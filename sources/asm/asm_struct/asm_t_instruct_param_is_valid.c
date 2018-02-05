/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_instruct_param_is_valid.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:00:55 by mressier          #+#    #+#             */
/*   Updated: 2017/10/26 14:00:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

#define DIR_LABEL_PARAM_CHARS		2
#define INDIR_LABEL_PARAM_CHARS		1

static int		internal_get_param_code_from_type(t_param_type type)
{
	int		params_code[NB_PARAM_TYPE];

	if (type == INVALID_PARAM || type >= NB_PARAM_TYPE)
		return (0);
	params_code[REG_PARAM] = T_REG;
	params_code[DIR_PARAM] = T_DIR;
	params_code[DIR_LABEL_PARAM] = T_DIR;
	params_code[INDIR_PARAM] = T_IND;
	params_code[INDIR_LABEL_PARAM] = T_IND;
	return (params_code[type]);
}

static int		internal_label_param_exist(const char *param, t_label *list)
{
	char			*label_name;
	t_param_type	param_type;

	param_type = asm_get_param_type(param);
	if (param_type != DIR_LABEL_PARAM && param_type != INDIR_LABEL_PARAM)
		return (EXIT_SUCCESS);
	label_name = (char *)param;
	if (param_type == DIR_LABEL_PARAM)
		label_name = label_name + DIR_LABEL_PARAM_CHARS;
	else if (param_type == INDIR_LABEL_PARAM)
		label_name = label_name + INDIR_LABEL_PARAM_CHARS;
	if (asm_t_label_find(list, (void *)label_name,
			asm_is_label_name_equal) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int		internal_one_param_is_valid(const char *param, int exp_param)
{
	int					param_code;
	t_param_type		param_type;

	if (param == NULL && exp_param == 0)
		return (EXIT_SUCCESS);
	if (param == NULL || exp_param == 0)
		return (EXIT_FAILURE);
	param_type = asm_get_param_type(param);
	param_code = internal_get_param_code_from_type(param_type);
	if (!(exp_param & param_code))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				asm_t_instruct_param_is_valid(t_parser *parser,
					t_instruct *instruct, t_label *label_list,
					const char *new_param)
{
	int					expect_params[PARAM_MAX];
	int					param_nb;

	asm_get_expected_params(asm_get_instruct_type(instruct->name),
		expect_params);
	param_nb = asm_t_instruct_param_count(instruct->param);
	if (param_nb >= PARAM_MAX || internal_one_param_is_valid(new_param,
			expect_params[param_nb]) == EXIT_FAILURE)
	{
		if (new_param != NULL
				&& asm_get_word_type(new_param) == INVALID_WORD_TYPE)
		{
			return (asm_message_error(LEXICAL_ERR, parser->file_content,
				parser->current_ptr));
		}
		return (asm_param_error(instruct, parser->file_content,
			parser->current_ptr));
	}
	if (internal_label_param_exist(new_param, label_list) == EXIT_FAILURE)
	{
		return (asm_message_error("Invalid reference to a label at",
			parser->file_content, parser->current_ptr));
	}
	return (EXIT_SUCCESS);
}

int				asm_t_instruct_param_number_is_valid(t_parser *parser,
					t_instruct *instruct)
{
	int					expect_params[PARAM_MAX];
	int					i;

	asm_get_expected_params(asm_get_instruct_type(instruct->name),
		expect_params);
	i = 0;
	while (i < PARAM_MAX)
	{
		if ((instruct->param[i] == NULL && expect_params[i] != 0)
				|| (instruct->param[i] != NULL && expect_params[i] == 0))
		{
			return (asm_param_error(instruct, parser->file_content,
				parser->current_ptr));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
