CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=libftprintf.a

TEST_NAME=libftprintf.out

MY_SOURCES= ft_printf.c \
			ft_printf_utils2.c \
			ft_printf_utils1.c \
			ft_printf_struct_utils.c

MY_OBJECTS=$(MY_SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar -crs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -g3 $<

clean:
	rm -rf *.o $(MY_OBJECTS)

fclean: clean
	rm -rf $(NAME)

tclean: fclean
	rm -rf $(TEST_NAME)

bonus: all

norminette:
	norminette $(MY_SOURCES)

re: fclean all
