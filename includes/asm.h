/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:44:13 by mressier          #+#    #+#             */
/*   Updated: 2017/10/29 04:49:45 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "asm_parser.h"

# include <stdlib.h>
# include <unistd.h>

# define LABEL_LENGTH_MAX		128
# define INSTRUCT_LENGTH_MAX 	5
# define REGISTER_LENGTH_MAX	2
# define PARAM_MAX				3

/*
** ASM_INSTRUCT
*/

typedef struct				s_asm_instruct
{
	char					op_code;
	char					param_code;
	char					param[PARAM_MAX * 4];
	unsigned int			param_size;
	unsigned int			byte_count;
	unsigned int			starting_byte;
	struct s_asm_instruct	*next;
}							t_asm_instruct;

/*
** INSTRUCT
*/

typedef struct				s_instruct
{
	char					name[INSTRUCT_LENGTH_MAX + 1];
	char					*param[PARAM_MAX];
	struct s_instruct		*next;
}							t_instruct;

/*
** LABEL
*/

typedef struct				s_label
{
	char					name[LABEL_LENGTH_MAX];
	int						starting_byte;
	t_instruct				*instruct_list;
	t_asm_instruct			*asm_instruct_list;
	struct s_label			*next;
}							t_label;

/*
** ASM
*/

typedef struct				s_asm
{
	t_header				header;
	t_label					*label_list;
}							t_asm;

/*
** CORE
*/

/*
** asm_usage.c
*/
int							asm_usage(void);

# define SYNTAX_ERR			"SYNTAX_ERROR"
# define LEXICAL_ERR		"LEXICAL_ERROR"

/*
** asm_syntax_error.c
*/
int							asm_message_error(const char *message,
								const char *start_file, const char *error_ptr);
int							asm_word_type_error(t_word_type word_type,
								const char *start_file, const char *error_ptr);

/*
** asm_param_error.c
*/
int							asm_param_error(t_instruct *instruct,
								const char *start_file, const char *error_ptr);

/*
** READDER
*/

/*
** get_file_content.c
*/
int							asm_get_file_content(const char *filename,
								char **out_content);

/*
** asm_line_is_comment.c
*/
int							asm_line_is_comment(const char *line);
char						*asm_skip_commented_lines(const char *line);

/*
** asm_get_next_instruct.c
*/
char						*asm_get_next_instruct(const char *file_content);
char						*asm_get_eol_or_next_instruct(const char *string);

/*
** asm_get_asm_from_file_content.c
*/
int							asm_get_asm_from_file_content(const char *file,
								t_asm *asm_content);

int							asm_get_labels_and_instructs(t_parser *parser,
								t_label **list_to_set);

/*
** asm_file.c
*/
void						asm_file_skip_label(t_parser *parser);
int							asm_is_param_separator(int c);

/*
** STRUCTS
*/

/*
** asm_t_display.c
*/
void						asm_t_asm_display(t_asm asm_content);
void						asm_t_asm_init(t_asm *asm_content);
void						asm_t_asm_del_content(t_asm asm_content);

/*
** header
*/
typedef int					(*t_ft_parse_header)(t_parser *, t_header *);

int							asm_t_header_init_from_file(t_parser *parser,
								t_header *out_header);

int							asm_t_header_get_name(t_parser *parser,
								t_header *header);
int							asm_t_header_get_comment(t_parser *parser,
								t_header *header);

/*
** label
*/
t_label						*asm_t_label_new(void);
void						asm_t_label_del(t_label **label);
void						asm_t_label_del_list(t_label *label);
t_label						*asm_t_label_add_end(t_label *list, t_label *add);
void						asm_t_label_display_list(t_label *list);

typedef int					(*t_asm_label_cmp)(t_label *, void *);

t_label						*asm_t_label_find(t_label *list,
								void *data, t_asm_label_cmp find);
int							asm_is_label_name_equal(t_label *label, void *data);

int							asm_t_label_init_from_file(t_parser *parser,
								t_label **list_to_set);

/*
** instruct
*/
t_instruct					*asm_t_instruct_new(void);
void						asm_t_instruct_del(t_instruct **instruct);
void						asm_t_instruct_del_list(t_instruct *instruct);
t_instruct					*asm_t_instruct_add_end(t_instruct *list,
								t_instruct *add);
void						asm_t_instruct_display_list(t_instruct *list,
								int tab);
int							asm_t_instruct_param_count(char **params);

int							asm_t_instruct_init_list_from_file(t_parser *parser,
								t_label *label_list);

int							asm_t_instruct_init_from_file(t_parser *parser,
								t_label *label, t_label *label_list);
int							asm_t_instruct_param_go_to_next_param(t_parser *p);

/*
** instruct param
*/
void						asm_t_instruct_param_init(char **params);
void						asm_t_instruct_param_del(char **params);
int							asm_t_instruct_param_add_end(char **param,
								char *new_param);
void						asm_t_instruct_param_display(char **params,
								int tab);

int							asm_t_instruct_param_init_from_file(t_parser *prs,
								t_instruct *instruct, t_label *label_list);

int							asm_t_instruct_param_is_valid(t_parser *parser,
								t_instruct *instruct, t_label *label_list,
								const char *new_param);
int							asm_t_instruct_param_number_is_valid(t_parser *prs,
								t_instruct *instruct);

/*
** asm_instruct
*/
t_asm_instruct				*asm_t_asm_instruct_new(void);
void						asm_t_asm_instruct_del(t_asm_instruct **instruct);
void						asm_t_asm_instruct_del_list(t_asm_instruct *list);
void						asm_t_asm_instruct_add_to_end(t_asm_instruct **list,
								t_asm_instruct *add);
void						asm_t_asm_instruct_init_list(t_asm
								*asm_file_content);
void						asm_t_asm_instruct_init(t_asm_instruct
								*asm_instruct, t_instruct *target,
								unsigned int current_byte);
void						asm_t_asm_instruct_byte_and_param_count(
								t_asm_instruct *asm_instruct,
								t_instruct *target);
void						asm_t_asm_instruct_get_param_size(
								t_asm_instruct *asm_instruct,
								t_instruct *target, int size);
void						asm_t_asm_instruct_display_list(
								t_asm_instruct *list, int tab);

/*
** asm_instruct_param
*/
char						asm_t_asm_instruct_get_param_code(char **params);
void						asm_t_asm_instruct_init_params(
								t_asm *asm_file_content);
void						asm_t_asm_instruct_fill_param(t_asm_instruct
								*asm_instruct, t_instruct *target,
								t_label *label_list);
int							asm_t_asm_instruct_identify_param_type(char *param);
unsigned int				asm_t_asm_instruct_find_label(char *param,
								t_label *label_list);
unsigned int				asm_t_asm_instruct_get_current_param_size(
								char *param, t_asm_instruct *asm_instruct);
void						asm_t_asm_instruct_convert_label_address_to_bytes(
								int param, char *dest, int size);
void						asm_t_asm_instruct_convert_char_param_to_bytes(
								char *param, char *dest, int size);

/*
** WRITE
*/

int							asm_write_asm_to_file(t_asm *asm_file_content,
								char *original_filename);
void						asm_write_header_to_file(t_asm *asm_file_content,
								int fd);
void						asm_write_t_asm_instruct_list_to_file(
								t_label *label, int fd);
void						asm_write_t_asm_instruct_to_file(
								t_asm_instruct *instruct, int fd);

/*
** TOOLS
*/

/*
** asm_is_one_of_label_char.c
*/
int							asm_is_one_of_label_char(int c);

/*
** asm_error_tools.c
*/
void						asm_error_concat_line_and_char(const char *start,
								const char *ptr, char *str_error);
void						asm_error_get_word_error(const char *error_ptr,
								char *word_error, int size_max);

#endif
