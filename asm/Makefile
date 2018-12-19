# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feedme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 19:21:17 by feedme            #+#    #+#              #
#    Updated: 2018/12/05 19:59:14 by feedme           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = *.c
LIB = ../libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)

lldb:
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -g

sanitize:
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -fsanitize=address -g

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)*

re: fclean all
