/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:13:04 by mressier          #+#    #+#             */
/*   Updated: 2017/10/26 14:13:05 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PARSER_H
# define ASM_PARSER_H

# include "op.h"

# include <stdlib.h>

/*
** PARSER
*/

typedef struct				s_parser
{
	char					*file_content;
	char					*current_ptr;
}							t_parser;

/*
** word_type
*/

typedef enum				e_word_type
{
	INVALID_WORD_TYPE = -1,
	COMMAND_NAME = 0,
	COMMAND_COMMENT,
	LABEL,
	INSTRUCTION,
	SEPARATOR,
	STRING,
	END_OF_LINE,
	END_OF_FILE,
	REG_PARAM_WORD,
	DIR_PARAM_WORD,
	DIR_LABEL_PARAM_WORD,
	INDIR_PARAM_WORD,
	INDIR_LABEL_PARAM_WORD,
	NB_WORD_TYPE
}							t_word_type;

/*
** param_type
*/

typedef enum				e_param_type
{
	INVALID_PARAM = -1,
	REG_PARAM = 0,
	DIR_PARAM,
	DIR_LABEL_PARAM,
	INDIR_PARAM,
	INDIR_LABEL_PARAM,
	NB_PARAM_TYPE
}							t_param_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4

/*
** instruct_type
*/

typedef enum				e_instruct_type
{
	INVALID_INSTRUCT = -1,
	LIVE = 0,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF,
	NB_INSTRUCT_TYPE
}							t_instruct_type;

typedef int					(*t_asm_is)(const char *);

/*
** asm_get_instruct_type.c
*/
t_instruct_type				asm_get_instruct_type(const char *word);
char						*asm_t_instruct_type_to_string(t_instruct_type tp);

void						asm_get_expected_params(t_instruct_type type,
								int *params);

/*
** asm_get_word_type.c
*/
t_word_type					asm_get_word_type(const char *word);
char						*asm_t_word_type_to_string(t_word_type type);

/*
** asm_t_word_type_is.c
*/
int							asm_is_command_name(const char *word);
int							asm_is_command_comment(const char *word);
int							asm_is_label(const char *word);
int							asm_is_instruction(const char *word);
int							asm_is_end_of_file(const char *word);

/*
** asm_t_word_type_is_2.c
*/
int							asm_is_separator(const char *word);
int							asm_is_end_of_line(const char *word);
int							asm_is_string(const char *word);

/*
** asm_t_param_type_is.c
*/
int							asm_is_numeric(const char *word);
int							asm_is_param_label(const char *word);
int							asm_param_is_register(const char *word);

/*
** asm_t_param_type_is_2.c
*/
int							asm_param_is_direct(const char *word);
int							asm_param_is_indirect(const char *word);
int							asm_param_is_direct_label(const char *word);
int							asm_param_is_indirect_label(const char *word);

/*
** asm_get_param_type.c
*/
t_param_type				asm_get_param_type(const char *word);
char						*asm_t_param_type_to_string(t_param_type type);

#endif
