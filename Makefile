OBJECTS = *.o
SRC = 

LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror
NAME = corewar

all: $(NAME)

$(NAME):
	make -C libft/
	make -C asm/
	make -C vm/
	make -C terminal/
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIB)

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
 
