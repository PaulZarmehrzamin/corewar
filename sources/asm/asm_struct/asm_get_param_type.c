/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_param_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:27:34 by mressier          #+#    #+#             */
/*   Updated: 2017/10/26 11:27:35 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void				internal_init_param_type_tab(t_asm_is *ft_asm_is)
{
	ft_asm_is[REG_PARAM] = asm_param_is_register;
	ft_asm_is[DIR_PARAM] = asm_param_is_direct;
	ft_asm_is[DIR_LABEL_PARAM] = asm_param_is_direct_label;
	ft_asm_is[INDIR_PARAM] = asm_param_is_indirect;
	ft_asm_is[INDIR_LABEL_PARAM] = asm_param_is_indirect_label;
}

t_param_type			asm_get_param_type(const char *word)
{
	t_asm_is		ft_asm_is[NB_PARAM_TYPE];
	int				i;

	i = 0;
	internal_init_param_type_tab(ft_asm_is);
	while (i < NB_PARAM_TYPE)
	{
		if (ft_asm_is[i](word))
			return (i);
		i++;
	}
	return (INVALID_PARAM);
}

char					*asm_t_param_type_to_string(t_param_type type)
{
	char		*params[NB_PARAM_TYPE];

	if (type == INVALID_PARAM || type > NB_PARAM_TYPE)
		return ("unknow parameter type");
	params[REG_PARAM] = "register";
	params[DIR_PARAM] = "direct";
	params[DIR_LABEL_PARAM] = "direct label";
	params[INDIR_PARAM] = "indirect";
	params[INDIR_LABEL_PARAM] = "indirect label";
	return (params[type]);
}
