/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 13:58:48 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/01 15:58:12 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void	remove(t_map *map, t_tetrimino *list,
int start_x, int start_y)
{
	int x;
	int y;

	y = 0;
	while (y < list->h)
	{
		x = 0;
		while (x < list->w)
		{
			if (list->array[y][x] == INPUT_BLOCK_CHAR)
			{
				map->field[start_y + y][start_x + x] = EMPTY_CHAR;
			}
			x++;
		}
		y++;
	}
}

static void	place(t_map *map, t_tetrimino *list,
int start_x, int start_y)
{
	int x;
	int y;

	y = 0;
	while (y < list->h)
	{
		x = 0;
		while (x < list->w)
		{
			if (list->array[y][x] == INPUT_BLOCK_CHAR)
			{
				map->field[start_y + y][start_x + x] = list->value;
			}
			x++;
		}
		y++;
	}
}

static int	can_place(t_map *map, t_tetrimino *list,
int start_x, int start_y)
{
	int x;
	int y;

	y = 0;
	while (y < list->h)
	{
		x = 0;
		while (x < list->w)
		{
			if (list->array[y][x] == INPUT_BLOCK_CHAR &&
			map->field[start_y + y][start_x + x] != EMPTY_CHAR)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	solver(t_map *map, t_tetrimino *list)
{
	int		x;
	int		y;

	if (list == NULL)
		return (1);
	y = 0;
	while (y <= map->field_size - list->h)
	{
		x = 0;
		while (x <= map->field_size - list->w)
		{
			if (can_place(map, list, x, y))
			{
				place(map, list, x, y);
				if (solver(map, list->next))
					return (1);
				else
					remove(map, list, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map		*solve(t_tetrimino *list)
{
	t_map *map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->field_size = get_input_block_count(list);
	if (alloc_map(map) == -1)
		return (NULL);
	while (solver(map, list) != 1)
	{
		free_map(map);
		map->field_size++;
		if (alloc_map(map) == -1)
			return (NULL);
	}
	return (map);
}
