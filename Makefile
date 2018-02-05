# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 11:48:22 by pzarmehr          #+#    #+#              #
#    Updated: 2017/10/29 14:15:10 by mplanell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEASM = asm
NAMECOR = corewar
CC = gcc
FLAGS = -Wall -Werror -Wextra

PATH_LIBFT = ./libft/includes
LFT = -L ./libft/ -l ft -lncurses

PATH_ASM = ./sources/asm/
PATH_COR = ./sources/corewar/
PATH_SRC = ./sources/
PATH_INC = ./includes/

# INCLUDES #

INC_FILES = asm.h \
			op.h \
			corewar.h

INCLUDES = $(addprefix $(PATH_INC), $(INC_FILES))
# ASM #

ASM_CORE = main.c \
			asm_usage.c \
			asm_error.c \
			asm_param_error.c
ASM_SRC_CORE = $(addprefix core/, $(ASM_CORE))

ASM_READDER = asm_get_file_content.c \
				asm_file.c \
				asm_skip_commented_line.c \
				asm_get_next_instruct.c \
				asm_get_asm_from_file_content.c \
				asm_get_labels_and_instructs.c \
				asm_t_header_init_from_file.c \
				asm_t_label_init_from_file.c \
				asm_t_instruct_init_from_file.c \
				asm_t_instruct_init_list_from_file.c \
				asm_t_instruct_param_init_from_file.c
ASM_SRC_READDER = $(addprefix asm_readder/, $(ASM_READDER))

ASM_STRUCT = asm_t_header_get_datas.c \
				asm_t_asm.c \
				asm_t_label.c \
				asm_t_label_tools.c \
				asm_t_instruct.c \
				asm_t_instruct_param.c \
				asm_t_word_type_is.c \
				asm_t_word_type_is_2.c \
				asm_get_word_type.c \
				asm_t_param_type_is.c \
				asm_t_param_type_is_2.c \
				asm_get_param_type.c \
				asm_get_instruct_type.c \
				asm_t_instruct_param_is_valid.c \
				asm_get_expected_params.c \
				asm_t_asm_instruct.c \
				asm_t_asm_instruct_encoding_byte.c \
				asm_t_asm_instruct_byte_count.c \
				asm_t_asm_instruct_fill_param.c \
				asm_t_asm_instruct_fill_param_tools.c \
				asm_t_asm_instruct_init.c \
				asm_t_asm_instruct_display.c
ASM_SRC_STRUCT = $(addprefix asm_struct/, $(ASM_STRUCT))

ASM_WRITE = asm_write_asm_to_file.c \
			asm_write_header_to_file.c \
			asm_write_asm_instruct_to_file.c
ASM_SRC_WRITE = $(addprefix asm_write/, $(ASM_WRITE))

ASM_TOOLS = asm_error_tools.c \
				asm_is_one_of_label_char.c
ASM_SRC_TOOLS = $(addprefix tools/, $(ASM_TOOLS))

SRCASM = $(ASM_SRC_CORE) $(ASM_SRC_READDER) $(ASM_SRC_STRUCT) $(ASM_SRC_TOOLS) \
		 $(ASM_SRC_WRITE)

LIB = libft/libft.a

# COR #

SRCCOR = cor_main.c \
		get_players.c \
		struct_player.c \
		usage.c \
		struct_argv.c \
		resolve_dump.c \
		resolve_n.c \
		resolve_champ.c \
		resolve_verb.c \
		resolve_speed.c \
		debug.c \
		struct_pcs.c \
		struct_game.c \
		check_cycle.c \
		print_verb.c \
		cor_run.c \
		cor_run_pc.c \
		get_wait.c \
		get_cmd.c \
		cmd_tools.c \
		cmd_live.c \
		cmd_ld.c \
		cmd_st.c \
		cmd_addsub.c \
		cmd_bit.c \
		cmd_zjmp.c \
		cmd_fork.c \
		cmd_aff.c \
		make_player_list.c \
		print_winner.c \
		print_arena.c \
		get_pcs.c \
		error_get_players.c \
		resolve_graph.c \
		graph_init.c \
		graph_head.c \
		struct_display.c \
		graph_arena.c \
		graph_init_arena.c \
		graph_end_cycle.c \
		graph_print_winner.c \
		graph_head_speed.c
SRCALL =

OBJASM = $(patsubst %.c,%.o,$(addprefix $(PATH_ASM), $(SRCASM)))
OBJCOR = $(patsubst %.c,%.o,$(addprefix $(PATH_COR), $(SRCCOR)))
OBJALL = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRCALL)))

#############
# ! COLOR ! #
#############

NONE = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[36m

all: $(LIB) $(NAMEASM) $(NAMECOR) $(OBJALL)

$(LIB):
	@make -C libft
	@echo "$(CYAN)\n\nCompiling $(NAMEASM) and $(NAMECOR) :$(NONE)\n"

$(NAMEASM): $(LIB) $(OBJASM) $(OBJALL)
	@$(CC) $(FLAGS) -o $(NAMEASM) $(OBJASM) $(OBJALL) $(LFT)
	@echo "[$(GREEN) CREATE $(NONE)]         $(YELLOW)$(NAMEASM)$(NONE)\n"

$(NAMECOR): $(LIB) $(OBJCOR) $(OBJALL)
	@$(CC) $(FLAGS) -o $(NAMECOR) $(OBJCOR) $(OBJALL) $(LFT)
	@echo "[$(GREEN) CREATE $(NONE)]         $(YELLOW)$(NAMECOR)$(NONE)\n"

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $^ -I $(PATH_INC) -I $(PATH_LIBFT)
	@echo "[$(GREEN) COMPIL $(NONE)]         $(YELLOW)$<$(NONE)"

clean:
	@make -C libft clean
	@rm -f $(OBJASM) $(OBJCOR) $(OBJALL)
	@echo "[$(GREEN) DELETED $(NONE)] $(YELLOW)Objects Project$(NONE)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAMEASM) $(NAMECOR)
	@echo "[$(GREEN) DELETED $(NONE)] $(YELLOW)Binary Project$(NONE)"

re: fclean all

.PHONY: all clean fclean re
