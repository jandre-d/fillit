/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/01/31 15:21:44 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_byte	set_initial_size_sqrt(int block_count)
{
	if (block_count == 0)
		return (0);

}

static t_byte	set_initial_size_count(t_tetrimino list)
{

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
