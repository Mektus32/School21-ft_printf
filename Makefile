# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 20:39:18 by ojessi            #+#    #+#              #
#    Updated: 2019/05/06 20:42:47 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
SRC = libft/*.c\
	  src/*.c
HEAD = includes
FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I $(HEAD) $(SRC) -o $(NAME)
	./$(NAME)

clean:
	/bin/rm -f $(NAME)

re: clean all

.PHONY: re clean all
