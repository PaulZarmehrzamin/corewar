/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:34:52 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/31 15:16:46 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

/*
** ASM
*/
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define COMMENT_CHAR			'#'
# define STRING_CHAR			'"'
# define REGISTER_CHAR			'r'

/*
** Header
*/
# define NAME_CMD_STRING			".name"
# define NAME_CMD_STRING_SIZE		sizeof(".name")
# define COMMENT_CMD_STRING			".comment"
# define COMMENT_CMD_STRING_SIZE	sizeof(".comment")

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

/*
** Code
*/
# define REG_CODE				0b01
# define DIR_CODE				0b10
# define IND_CODE				0b11

/*
** Type
*/
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
** Registre
*/
# define REG_NUMBER				16
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define IND_SIZE				2

/*
** Memory
*/
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

/*
** Cycle
*/
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
**  Header
*/
typedef	struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

#endif
