NAME = libft.a

CC = cc

LIB = ar rcs

FLAGS = -Werror -Wall -Wextra // includes gnl?

PRINTF_PATH = Printf

OBJS_DIR = objs

GNL_PATH = Get_next_line

FILES = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	$(GNL_PATH)/get_next_line.c\
	$(GNL_PATH)/get_next_line_bonus.c\
	$(GNL_PATH)/get_next_line_utils.c\
	$(GNL_PATH)/get_next_line_utils_bonus.c\

BONUS = ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\

OBJECTS = $(FILES:%.c=$(OBJS_DIR)/%.o)
OBJ_BONUS = $(BONUS:%.c=$(OBJS_DIR)/%.o)

all: printf $(NAME)

printf:
	@if [ ! -f "$(PRINTF_PATH)/libftprintf.a" ]; then make -s -C $(PRINTF_PATH)

$(NAME): $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

bonus: $(OBJECTS) $(OBJ_BONUS)
	$(LIB) $(NAME) $(OBJECTS) $(OBJ_BONUS)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "libft clean done!"
	@make clean -s -C $(PRINTF_PATH)

fclean: clean
	@rm -f $(NAME)
	@echo "libft fclean done!"
	@make fclean -s -C $(PRINTF_PATH)

re: fclean all

.PHONY: re all clean fclean bonus printf
