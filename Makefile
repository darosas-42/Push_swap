NAME = push_swap

CC = cc

LIB = ar rcs

FLAGS = -Wall -Werror -Wextra -g

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

FILES = push_swap.c\
		utils.c\

OBJECTS = $(FILES:.c=.o)

all:libft $(NAME)

libft:
	@if [ ! -f "$(LIBFT)" ]; then \
		make -s -C $(LIBFT_PATH); \
	fi

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) -o push_swap

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJ_BONUS)
	@make clean -s -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	@make fclean -s -C $(LIBFT_PATH)

re: fclean all

.PHONY: re all clean fclean