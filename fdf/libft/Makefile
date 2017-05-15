# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 15:12:07 by bdesbos           #+#    #+#              #
#    Updated: 2016/11/02 20:28:31 by bdesbos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_printbits.c \
	  ft_racinecarree.c \
	  ft_premier.c \
	  ft_premiersuiv.c \
	  ft_isspace.c \
	  ft_isblank.c \
	  ft_pow2.c \
	  ft_lstpush_np.c \
	  ft_lstlen.c \
	  ft_lstlast.c \
	  ft_strrev.c \
	  ft_strjoinf.c \
	  ft_strjoinkf.c \
	  ft_strjoinff.c \
	  ft_strsubf.c \
	  ft_gnl.c \
	  ft_putendlf.c \
	  ft_strcatf.c \
 	  ft_tabfree.c \
	  ft_putendlf_fd.c \
	  ft_strisalnum.c \
	  ft_strisdigit.c

SRCO = $(SRC:.c=.o)

all: $(NAME)
 
$(NAME): $(SRCO)
	@ar rcs $@ $^
	@echo "libft, delivreeee"

.c.o:
	@gcc -Wall -Werror -Wextra -o $@ -c $< -g

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
