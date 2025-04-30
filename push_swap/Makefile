NAME = push_swap.a

CC = cc

LIB = ar rcs

FLAGS = -Wall -Werror -Wextra

FILES = 

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIB) $(FLAGS) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean