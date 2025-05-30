NAME = push_swap

CC = cc

LIB = ar rcs

FLAGS = -Wall -Werror -Wextra -I Libft/includes -I includes

LIBFT_PATH = Libft
LIBFT = $(LIBFT_PATH)/libft.a

PS_PATH = src

PS_FILES = $(PS_PATH)/push_swap.c\
		$(PS_PATH)/utils.c\
		$(PS_PATH)/moves.c\
		$(PS_PATH)/sort.c\

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
	@rm -r $(OBJECTS)
	@make clean -s -C $(LIBFT_PATH)
	@echo "clean done!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_PATH)
	@echo "fclean done!"

re: fclean all

valgrind:
	$(eval ARG = $(shell shuf -i 0-100 -n 100))
	valgrind --leak-check=full ./$(NAME) $(ARG)

test2: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: re all clean fclean
