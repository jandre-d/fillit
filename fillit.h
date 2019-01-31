/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 15:55:39 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/31 14:01:30 by jandre-d      ########   odam.nl         */
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
	char				end_char;
	struct s_tetrimino	*next;
}						t_etrimino;

#endif
