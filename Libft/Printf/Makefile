NAME = libftprintf.a

CC = cc

LIB = ar rcs

FLAGS = -Wall -Werror -Wextra

OBJS_DIR = objs

FILES = ft_printf.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_unsnb.c\
	ft_address.c\
	ft_hexadec.c\

OBJECTS = $(FILES:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)
	mkdir -p $(OBJS_DIR)

clean:
	@rm -f $(OBJECTS)
	@echo "clean done!"

fclean: clean
	@rm -f $(NAME)
	@echo "clean done!"

re: fclean all

.PHONY: re all clean fclean
