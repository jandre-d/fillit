# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/26 15:51:07 by tde-jong       #+#    #+#                 #
#    Updated: 2019/02/05 16:58:06 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

LIB = -L libft -lft

SRC = fillit.c input.c list.c map.c solver.c

all: $(NAME)

$(NAME):
	make lib
	gcc $(FLAGS) $(SRC) -c
	gcc $(FLAGS) $(SRC:.c=.o) -o $(NAME) $(LIB)

clean:
	rm -f $(SRC:.c=.o)
	rm -f *~
	rm -f \#*#

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

lib:
	cd libft && make re && make clean && cd ..

test: all
	rm -f README.md
	rm -f .travis.yml
	git clone https://github.com/jgigault/42FileChecker ~/42FileChecker
	bash ~/42FileChecker/42FileChecker.sh --project "fillit" \
	--path "${TRAVIS_BUILD_DIR}" --no-norminette
