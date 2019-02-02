/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/02 17:12:54 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int				get_initial_size_sqrt(int block_count)
{
	int a;

	a = 0;
	while (a * a < block_count)
	{
		a++;
	}
	return (a);
}

void			free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->field_size)
	{
		ft_memdel((void *)map->field[i]);
		i++;
	}
	ft_memdel((void **)map->field);
}

int				alloc_map(t_map *map)
{
	int i;

	i = 0;
	map->field = (char **)ft_memalloc(map->field_size + 1);
	if (map->field == NULL)
		return (-1);
	while (i < map->field_size)
	{
		map->field[i] = (char *)ft_strnew(map->field_size + 1);
		if (map->field[i] == NULL)
			return (-1);
		i++;
	}
	return (1);
}
