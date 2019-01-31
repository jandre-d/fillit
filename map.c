/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/01/31 18:06:38 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_byte	get_initial_size_sqrt(int block_count)
{
	int a;

	a = 0;
	while (1)
	{
		if ((a * a) >= block_count)
			return (a);
		a++;
	}
	return (0);
}

static int	get_input_block_count(t_tetrimino *list)
{
	int			block_count;
	t_tetrimino *lst;
	t_byte		i;
	t_byte		j;

	block_count = 0;
	lst = list;
	while (lst != NULL)
	{
		i = 0;
		while (j < lst->h)
		{
			j = 0;
			while (i < lst->w)
			{
				if (lst->array[i][j] == '#')
					block_count++;
				j++;
			}
			i++;
		}
		lst = lst->next;
	}
	return (block_count);
}

t_byte	set_initial_size(t_state state)
{
	return (0);
}

void	free_map(t_state state)
{
	t_byte i;

	i = 0;
	while (i < state.field_size)
	{
		ft_memdel((void **)state.field[i]);
		i++;
	}
}

int		alloc_map(t_state state)
{
	t_byte i;

	i = 0;
	if ((state.field = (char **)ft_memalloc(state.field_size)) == NULL)
		return (-1);
	while (i < state.field_size)
	{
		if ((state.field[i] = (char *)ft_strnew(state.field_size)) == NULL)
			return (-1);
		i++;
	}
}
