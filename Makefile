# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tde-jong <tde-jong@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/26 15:51:07 by tde-jong       #+#    #+#                 #
#    Updated: 2019/01/28 09:59:01 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

BUILDLIB = cd libft && make re && cd ..

LIB = -L libft -lft

SRC = *.c

all: $(NAME)

$(NAME):
	$(BUILDLIB) && gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	rm -f $(SRC:.c=.o)
	rm -f *~
	rm -f \#*#
	cd libft && make clean && cd ..

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean && cd ..

re: fclean all
