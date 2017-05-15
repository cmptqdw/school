# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 15:12:07 by bdesbos           #+#    #+#              #
#    Updated: 2016/01/21 22:06:08 by bdesbos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

SRC = main.c ft_error.c ft_readfile.c ft_strnew_point.c ft_resolve.c \
	 ft_verifblocs.c ft_printsquare.c ft_stockblocs.c ft_sqrt.c ft_veriffile.c 

SRCO = $(SRC:.c=.o)

all: $(NAME)
 
$(NAME): $(SRCO)
	gcc -Wall -Werror -Wextra -o $@ $^ libft.a

.c.o:
	gcc -Wall -Werror -Wextra -o $@ -c $<

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
