/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelmer <jelmer@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/01 09:45:24 by jelmer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "fillit.h"

static t_byte	get_initial_size_sqrt(int block_count);
static int	get_input_block_count(t_tetrimino *list);
void	free_map(t_state *state);
int		alloc_map(t_state *state);

#endif
