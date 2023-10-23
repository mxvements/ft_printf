CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=libftprintf.a

TEST_NAME=libftprintf.out

MY_SOURCES= ft_printf.c

MY_OBJECTS=$(MY_SOURCES:%.a=%.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar -crs $@ $^

clean:
	rm -rf *.o $(MY_OBJECTS)

fclean: clean
	rm -rf $(NAME)

tclean: fclean
	rm -rf $(TEST_NAME)

norminette:
	norminette $(MY_SOURCES)

re: fclean all
