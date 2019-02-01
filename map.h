/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/01 15:57:40 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "fillit.h"

int				get_initial_size_sqrt(int block_count);
void			free_map(t_map *map);
int				alloc_map(t_map *map);

#endif
