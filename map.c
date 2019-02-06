/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/06 15:14:58 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void			free_alles(t_tetrimino *tet_list, t_map *map)
{
	t_tetrimino *list;
	t_tetrimino *list_prev;
	int			x;
	int			y;

	x = 0;
	y = 0;
	list = tet_list;
	free_map(map);
	while (list != NULL)
	{
		list_prev = list;
		list = list->next;
		free_tetrimino_elem(list_prev);
	}
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
