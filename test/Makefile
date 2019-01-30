# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tde-jong <tde-jong@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/30 13:10:55 by tde-jong       #+#    #+#                 #
#    Updated: 2019/01/30 14:32:09 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit_test

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) input_check.c -L ../libft -lft -o input_check
	gcc $(FLAGS) main.c -L ../libft -lft -o $(NAME) -g

fclean:
	rm -f $(NAME)
	rm -f input_check

re: fclean all

test: re
	./fillit_test
