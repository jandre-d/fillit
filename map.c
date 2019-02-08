/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/08 17:21:27 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int		count_blocks(t_tetrimino *tet)
{
	int y;
	int x;
	int block_count;

	block_count = 0;
	y = 0;
	while (y < tet->h)
	{
		x = 0;
		while (x < tet->w)
		{
			if (tet->array[y][x] == INPUT_BLOCK_CHAR)
				block_count++;
			if (block_count > 4)
				return (-1);
			x++;
		}
		y++;
	}
	return (block_count);
}

int				get_initial_field_size(t_tetrimino *list)
{
	int			block_count;
	int			i;
	t_tetrimino *lst;

	lst = list;
	block_count = 0;
	while (lst != NULL)
	{
		if (count_blocks(lst) != 4)
			return (-1);
		else
			block_count += 4;
		lst = lst->next;
	}
	i = 0;
	while (i * i < block_count)
	{
		i++;
	}
	return (i);
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
	ft_memdel((void **)&map->field);
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
		if (map->field[i] == NULL)
			return (-1);
		ft_memset(map->field[i], '.', map->field_size);
		i++;
	}
	return (1);
}
