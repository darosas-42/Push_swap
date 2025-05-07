NAME = libftprintf.a

CC = cc

LIB = ar rcs

FLAGS = -Wall -Werror -Wextra

FILES = ft_printf.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_unsnb.c\
	ft_address.c\
	ft_hexadec.c\

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
