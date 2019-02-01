/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelmer <jelmer@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 13:58:48 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/01 10:01:47 by jelmer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static int get_next_place(t_state *state, t_point *dst, t_point *src)
{
	dst = ft_memcpy(dst, src, sizeof(t_point));
	if (dst->x == state->field_size - 1)
	{
		dst->y += 1;
		dst->x = 0;
		return (1);
	}
	if (dst->y == state->field_size)
	{
		return (0);
	}
}

static void remove_block(t_state *state, t_point *place)
{

}

static int place_block(t_state *state, t_point *place)
{
	return (1/* can place y/n */);
}

static int	solver(t_state *state, t_point my_place)
{
	t_tetrimino *cur_tet;

	cur_tet = state->tetriminos;
	while (cur_tet != NULL)
	{


	}

}

int	start_solve(t_state *state)
{
	t_point start_point;

	start_point.x = 0;
	start_point.y = 0;
	state->field_size = get_initial_size_sqrt(get_input_block_count(state->tetriminos));
	state->field = alloc_map(state);
	solver(state, start_point);
}
