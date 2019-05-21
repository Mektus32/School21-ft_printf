NAME = libftprintf.a
SRC = check_fmt.c choice_spec.c ft_atoi.c ft_bzero.c \
		ft_itoa.c ft_ltoa.c ft_nbrlen.c ft_printf.c \
		ft_strchr.c ft_strdup.c ft_strncmp.c \
		init_args.c print_digit.c print_spec.c \
		ft_free_strjoin.c ft_free_strjoin_rev.c \
		ft_free_strjoin_duo.c ft_strjoin.c \
		ft_strnew.c ft_memset.c ft_strlen.c
HEAD = -I includes
LIBFT = libft/*.c
OBJ = $(SRC:.c=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

CC = gcc
FLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) $(HEAD) $< -o $@

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@ranlib $@

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
