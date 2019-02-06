/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/06 11:23:42 by tde-jong      ########   odam.nl         */
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

void			print_map(t_map *block)
{
	int i;

	i = 0;
	while (i < block->field_size)
	{
		ft_putstr(block->field[i]);
		ft_putchar('\n');
		i++;
	}
}

void			free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->field_size)
	{
		ft_memdel((void **)&map->field[i]);
		i++;
	}
	ft_memdel((void **)map->field);
}

int				alloc_map(t_map *map)
{
	int i;

	i = 0;
	map->field = (char **)ft_memalloc((map->field_size + 1) * sizeof(char *));
	if (map->field == NULL)
		return (-1);
	while (i < map->field_size)
	{
		map->field[i] =
			(char *)ft_memalloc((map->field_size + 1) * sizeof(char));
		ft_memset(map->field[i], '.', map->field_size);
		if (map->field[i] == NULL)
			return (-1);
		i++;
	}
	return (1);
}
