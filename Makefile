# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tde-jong <tde-jong@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/26 15:51:07 by tde-jong       #+#    #+#                 #
#    Updated: 2019/01/26 15:54:11 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC = *.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(SRC:.c=.o)
	rm -f *~
	rm -f \#*#

flcean: clean
	rm -f $(NAME)

re: fclean all
