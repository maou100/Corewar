OBJECTS = *.o
SRC = ../op/op.c\
		src/main.c\
		src/arena.c\
		src/ft_get_player.c\
		src/ft_read_file.c\
		src/process.c\
		src/vm.c\
		src/one_to_five.c\
		src/instructions.c

LIB = ../libft/libft.a\

FLAGS = -Wall -Wextra -Werror -lncurses
NAME = vm

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIB) -fsanitize=address -g

sanitize:
	gcc $(FLAGS) $(SRC) -o $(NAME) -fsanitize=address -g $(LIB)

lldb:
	gcc $(FLAGS) -g $(SRC) -o $(NAME) $(LIB)

cleanlldb:
	rm $(NAME)
	rm -rf $(NAME).dSYM

runlldb:
	lldb ./$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
 
test:
	./$(NAME) ../zork.cor ../vm_champs/champs/Gagnant.cor
