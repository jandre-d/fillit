/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 15:55:39 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/31 14:09:08 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct			s_tetrimino
{
	char				**array;
	char				w;
	char				h;
	char				value;
	struct s_tetrimino	*next;
}						t_tetrimino;

typedef struct			s_state
{
	t_tetrimino			*tetriminos;
	char				**field;
	int					field_size;
}						t_state;

#endif
