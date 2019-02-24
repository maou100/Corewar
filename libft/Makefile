OBJECTS = *.o
BINAIRE = run
SOURCES = ft_atoi.c\
		  ft_bzero.c\
		  ft_isalnum.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isdigit.c\
		  ft_isprint.c\
		  ft_itoa.c\
		  ft_memalloc.c\
		  ft_memccpy.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memdel.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_putchar.c\
		  ft_putchar_fd.c\
		  ft_putendl.c\
		  ft_putendl_fd.c\
		  ft_putnbr.c\
		  ft_putnbr_fd.c\
		  ft_putstr.c\
		  ft_putstr_fd.c\
		  ft_putstr0x.c\
		  ft_strcat.c\
		  ft_strchr.c\
		  ft_strclr.c\
		  ft_strcmp.c\
		  ft_strcpy.c\
		  ft_strdel.c\
		  ft_strdup.c\
		  ft_strequ.c\
		  ft_striter.c\
		  ft_striteri.c\
		  ft_strjoin.c\
		  ft_strlcat.c\
		  ft_strlen.c\
		  ft_strmap.c\
		  ft_strmapi.c\
		  ft_strncat.c\
		  ft_strncmp.c\
		  ft_strncpy.c\
		  ft_strnequ.c\
		  ft_strnew.c\
		  ft_strrchr.c\
		  ft_strsplit.c\
		  ft_strstr.c\
		  ft_strnstr.c\
		  ft_strsub.c\
		  ft_strtrim.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_lstnew.c\
		  ft_lstdelone.c\
		  ft_lstdel.c\
		  ft_lstadd.c\
		  ft_lstiter.c\
		  ft_lstmap.c\
		  ft_str_is_print.c\
		  ft_strndup.c\
		  ft_strrevdup.c\
		  ft_strswap.c\
		  ft_strcat_from.c\
		  ft_strndup_from.c\
		  ft_strcpy_from_to.c\
		  ft_strdup_from.c\
		  ft_is_operation.c\
		  ft_realloc.c\
		  ft_clean_str.c\
		  ft_itoa_base.c\
		  ft_itoa_base_long.c\
		  get_next_line.c\
		  ft_mapdel.c\
		  ft_mapalloc.c\
		  ft_bin_to_dec.c\
		  ft_first_c_from_end.c\
		  ft_strnjoin.c\
		  ft_hex_to_decimal.c\
		  ft_power.c\
		  ft_exit_msg.c\
		  ft_strfjoin.c\
		  ft_char_to_bit.c


FLAGS = -Wall -Werror -Wextra -g
NAME = libft.a

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SOURCES) -I libft.h
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(BINAIRE)
	rm -f $(OBJECTS)


fclean: clean
	rm -f $(NAME)

re: fclean all
