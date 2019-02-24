OBJECTS = *.o
SOURCES = ../libft/*.c\
			ft_putint.c\
			get_terminal.c\
			terminal_off.c\
			terminal_on.c\
			ft_quit.c\
			receive_key.c\
			get_size.c

FLAGS = -Wall -Werror -Wextra
NAME = term.a

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SOURCES) -I term.h
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
