/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 13:27:39 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 15:11:45 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

static void	verify_tetrimino_rules(char **array, int col, int row, int *matches)
{
	if ((col > 0 && col < 3 && row > 0 && row < 3))
	{
		if (array[col][row - 1] == '#')
			(*matches)++;
		if (array[col][row + 1] == '#')
			(*matches)++;
		if (array[col - 1][row] == '#')
			(*matches)++;
		if (array[col + 1][row] == '#')
			(*matches)++;
	}
	else
	{
		if (col > 0 && array[col - 1][row] == '#')
			(*matches)++;
		if (col < 3 && array[col + 1][row] == '#')
			(*matches)++;
		if (row > 0 && array[col][row - 1] == '#')
			(*matches)++;
		if (row < 3 && array[col][row + 1] == '#')
			(*matches)++;
	}
}

static int	verify_tetrimino(t_tetrimino *tet)
{
	int col;
	int row;
	int matches;

	matches = 0;
	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			if (tet->array[col][row] == '#')
			{
				verify_tetrimino_rules(tet->array, col, row, &matches);
			}
			row++;
		}
		col++;
	}
	if (matches != 6 && matches != 8)
		return (0);
	return (1);
}

static char	**str_to_array(char *str)
{
	char	**array;
	int		i;

	if ((array = (char**)malloc(sizeof(char*) * 4)) == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if ((array[i] = (char*)ft_memalloc(sizeof(char) * 5)) == NULL)
			return (NULL);
		ft_memcpy(array[i], str, 4);
		array[i][5] = '\0';
		str = str + 5;
		i++;
	}
	return (array);
}

static int	add_terimino(char *str, t_state *state)
{
	if (state->tetriminos != NULL)
	{
		while (state->tetriminos->next != NULL)
			state->tetriminos = state->tetriminos->next;
		state->tetriminos = state->tetriminos->next;
	}
	state->tetriminos = ft_memalloc(sizeof(t_tetrimino));
	if ((state->tetriminos->array = str_to_array(str)) == NULL)
		return (0);
	if (!verify_tetrimino(state->tetriminos))
		return (0);
	return (1);
}

int			parse_input(char *filename, t_state *state)
{
	int			fd;
	int			ret;
	char		buff[22];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((ret = read(fd, buff, 21)))
	{
		buff[21] = '\0';
		if (ret < 20)
			return (1);
		if (!add_terimino(buff, state))
			return (0);
	}
	return (1);
}
