# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 22:19:26 by bdesbos           #+#    #+#              #
#    Updated: 2016/11/03 00:58:26 by bdesbos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell 

SRC_PATH = .

OBJ_PATH = obj

SRC_NAME = main.c error.c init.c ft_strtrim_sptab_f.c env.c lstmnew.c \
	  lstmfree.c msh_split_eq.c hub.c infos.c lstmadd.c msh_splitdv_chsp_f.c \
	  msh_strsplit_q.c exec.c msh_tablify_env.c cd.c unsetenv.c setenv.c \
	  checkandmajstruct.c signal.c def_shell_name.c ft_backtabfree.c lstmpush.c

INCL = -Iinclude

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

LIB = -L libft/ -lft

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ all
	@echo "a relink to the past"
	@$(CC) $(FLAGS) -o $(NAME) $^ $(LIB)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCL) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libft/ clean
	@echo "Coup de balay"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "Si tu tiens pas l'alcool, tiens au moins la serpillere"

re: fclean all

relib:
	cd libft; make clean; make; make clean

.PHONY: all clean fclean re relib
