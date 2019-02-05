# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/26 15:51:07 by tde-jong       #+#    #+#                 #
#    Updated: 2019/02/05 09:07:56 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -g

LIB = -L libft -lft

SRC = *.c

all: $(NAME)

$(NAME):
	cd libft && make
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	rm -f $(SRC:.c=.o)
	rm -f *~
	rm -f \#*#

fclean: clean
	rm -f $(NAME)

re: fclean all
