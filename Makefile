NAME = push_swap

CC = cc

LIB = ar rcs

FLAGS = -Wall -Werror -Wextra -g

LIBFT_PATH = Libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJS_DIR = objs

FILES = push_swap.c\
		utils.c\
		moves.c\

OBJECTS = $(FILES:%.c=$(OBJS_DIR)/%.o)

all:libft $(NAME)

libft:
	@if [ ! -f "$(LIBFT)" ]; then \
		make -s -C $(LIBFT_PATH); \
	fi

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

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
