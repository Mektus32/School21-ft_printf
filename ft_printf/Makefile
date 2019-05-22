NAME = libftprintf.a
SRC = src/*.c
HEAD = includes/
FLAGS = -c -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -I $(HEAD)
	@ar rc $(NAME) *.o

clean:
	@/bin/rm -rf *.o

fclean:	clean
	@/bin/rm -rf $(NAME)

re: fclean all 