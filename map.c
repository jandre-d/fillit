/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelmer <jelmer@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 14:34:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/01 10:20:27 by jelmer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		get_whitespace_count(t_state *state, t_point *till)
{


}

void	free_map(t_state *state)
{
	t_byte i;

	i = 0;
	while (i < state->field_size)
	{
		ft_memdel((void *)state->field[i]);
		i++;
	}
	ft_memdel((void **)state->field);
}

int		alloc_map(t_state *state)
{
	t_byte i;

	i = 0;
	if (
		(state->field = (char **)ft_memalloc(state->field_size)) == NULL)
		return (-1);
	while (i < state->field_size)
	{
		if (
			(state->field[i] = (char *)ft_strnew(state->field_size)) == NULL)
			return (-1);
		i++;
	}
}
