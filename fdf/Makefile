# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 22:19:26 by bdesbos           #+#    #+#              #
#    Updated: 2017/05/15 16:57:36 by bdesbos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

SRC_PATH = .

OBJ_PATH = obj

HEAD = fdf.h

SRC_NAME = main.c error.c fdf_parse.c lstpnew.c fdf_funkey.c fdf_draw.c \
		   fdf_norm.c fdf_awesome.c

INCL = -Iinclude

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

LIB = -L libft/ -lft 
MLX = -L /usr/local/lib/ -Iinclude/usr/local/include -lmlx

FRAMEW = -framework OpenGL -framework Appkit

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ all
	@echo "a relink to the past"
	@$(CC) $(FLAGS) -o $(NAME) $^ $(LIB) $(MLX) $(FRAMEW)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEAD)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) $(INCL) -o $@ -c $<

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
