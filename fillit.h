/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelmer <jelmer@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 15:55:39 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/31 18:50:28 by jelmer        ########   odam.nl         */
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

typedef struct			s_point
{
	t_byte				x;
	t_byte				y;
}						t_point;

#endif
