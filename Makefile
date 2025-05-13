NAME = push_swap

CC = cc

LIB = ar rcs

FLAGS = -Wall -Werror -Wextra -g -I Libft/includes -I includes

LIBFT_PATH = Libft
LIBFT = $(LIBFT_PATH)/libft.a

PS_PATH = src

OBJS_DIR = objs

PS_FILES = $(PS_PATH)/push_swap.c\
		$(PS_PATH)/utils.c\
		$(PS_PATH)/moves.c\

OBJECTS = $(PS_FILES:%.c=%.o)

all:libft $(NAME)

libft:
	@if [ ! -f "$(LIBFT)" ]; then \
		make -s -C $(LIBFT_PATH); \
	fi

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -s -C $(LIBFT_PATH)
	@echo "clean done!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_PATH)
	@echo "fclean done!"

re: fclean all

.PHONY: re all clean fclean
