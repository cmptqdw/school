# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 22:19:26 by bdesbos           #+#    #+#              #
#    Updated: 2016/04/12 15:36:36 by bdesbos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = align.c \
	  check_params.c \
	  files_and_errors.c \
	  ft_isroot.c \
	  ft_lslstadd_sort.c \
	  ft_lslstnew.c \
	  ft_lstadd_sort.c \
	  ft_print_filesname.c \
	  ft_smax.c \
	  ls_cmpptr.c \
	  ls_cmpsptr.c \
	  ls_cmpuuptr.c \
	  ls_error_msg.c \
	  lslst_free.c \
	  lst_free.c \
	  main.c \
	  print_dir.c \
	  print_errlst.c \
	  print_fltrights.c \
	  print_time.c \
	  recread.c \
	  rec_getsizesmax.c \
	  param_error_msg.c \
	  d_param_empty.c

LIB = -L libft/ -lft

CC = gcc

FLAGS = -Wall -Werror -Wextra -O3 -g3

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft/ all
	echo "a relink to the past"
	$(CC) $(FLAGS) -o $(NAME) $^ $(LIB)

.c.o:
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

relib:
	cd libft; make; make clean

.PHONY: all clean fclean re
