/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 15:55:39 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/31 14:45:34 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef char	t_byte;

typedef struct			s_tetrimino
{
	t_byte				**array;
	t_byte				w;
	t_byte				h;
	char				value;
	struct s_tetrimino	*next;
}						t_tetrimino;

typedef struct			s_state
{
	t_tetrimino			*tetriminos;
	char				**field;
	t_byte				field_size;
}						t_state;

#endif
