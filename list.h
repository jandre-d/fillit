/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:38:17 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/06 13:50:50 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "fillit.h"
# include "map.h"

t_tetrimino	*get_tetrimino_elem(char *buff, char *block_char);
void		free_tetrimino_elem(t_tetrimino *elem);

#endif
