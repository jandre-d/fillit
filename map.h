/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/06 14:01:36 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "fillit.h"
# include "list.h"

void			free_alles(t_tetrimino *tet_list, t_map *map);
int				get_initial_field_size(t_tetrimino *list);
void			print_block(t_tetrimino *block);
void			print_map(t_map *block);
void			free_map(t_map *map);
int				alloc_map(t_map *map);

#endif
