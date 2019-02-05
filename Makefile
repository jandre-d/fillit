# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/26 15:51:07 by tde-jong       #+#    #+#                 #
#    Updated: 2019/02/05 16:41:34 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

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

lib:
    cd libft && make re && make clean && cd ..

test: lib all
    git clone https://github.com/anisg/fillit_checker ~/fillit_checker
    bash ~/fillit_checker/test.sh ${TRAVIS_BUILD_DIR}
