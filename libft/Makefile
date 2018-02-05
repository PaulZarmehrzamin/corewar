# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 16:13:50 by pzarmehr          #+#    #+#              #
#    Updated: 2017/10/25 19:18:46 by mdezitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

PATH_SRC = ./
PATH_INC = ./includes/

SRC = ft_strlen.c \
	  ft_put1.c \
	  ft_put2.c \
	  ft_error.c \
	  ft_str.c \
	  get_next_line.c \
	  ft_bzero.c \
	  ft_memalloc.c \
	  ft_strequ.c \
	  ft_strtrim.c \
	  ft_memdel.c \
	  ft_strcat.c \
	  print_error.c \
	  syntax_error.c \
	  system_error.c \
	  ft_read_file.c \
	  ft_memjoin.c \
	  ft_putmemory.c \
	  ft_memcpy.c \
	  error.c \
	  ft_atoi.c \
	  ft_isdigit.c \
	  ft_putnbr.c \
	  ft_isnum.c \
	  ft_strsplit.c \
	  ft_strncpy.c \
	  ft_tablen.c \
	  ft_memtabdel.c \
	  ft_isspace.c \
	  ft_str_first_not.c \
	  ft_count_char.c \
	  ft_strrchr.c \
	  ft_strnequ.c \
	  swap_endian.c \
	  ft_itoa.c \
	  ft_isalpha.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

#############
# ! COLOR ! #
#############

NONE = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[36m

all: compil_lib $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\r[$(GREEN) CREATED $(NONE)]        $(YELLOW)$(NAME)$(NONE)"

compil_lib:
	@echo "$(CYAN)\nCompiling Libft :$(NONE)\n"

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $^ -I $(PATH_INC)
	@echo "[$(GREEN) COMPIL $(NONE)]         $(YELLOW)$<$(NONE)"

clean:
	@rm -f $(OBJ)
	@echo "\r[$(GREEN) DELETED $(NONE)] $(YELLOW)Objects Library$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@echo "\r[$(GREEN) DELETED $(NONE)] $(YELLOW)Binary Library$(NONE)"

re: fclean all

.PHONY: all clean fclean re
