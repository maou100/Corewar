# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feedme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/21 21:23:48 by feedme            #+#    #+#              #
#    Updated: 2018/10/18 23:29:22 by feedme           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

BINARIES = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft.h
	gcc $(FLAGS) -c $(SRC) -I libft.h get_next_line.h
	ar rc $(NAME) $(BINARIES)
	ranlib $(NAME)

clean:
	rm -f $(BINARIES)

fclean: clean
	rm -f $(NAME)

re: fclean all
