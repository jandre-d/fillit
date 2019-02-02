/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:38:14 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/02 17:14:54 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static char	**alloc_array(t_tetrimino *block)
{
	char	**to_return;
	int		x;

	x = 0;
	to_return = (char **)ft_memalloc(block->h * sizeof(char **) + 1);
	if (to_return == NULL)
		return (NULL);
	while (x < block->h)
	{
		to_return[x] = (char *)ft_memalloc(block->w * sizeof(char *) + 1);
		if (to_return[x] == NULL)
			return (NULL);
		x++;
	}
	return (to_return);
}

static void	set_size_width(char *buff, t_tetrimino *block, int *index_x_start)
{
	int x;

	x = 0;
	block->w = 4;
	*index_x_start = 42;
	while (x < 4)
	{
		if (buff[x] == EMPTY_CHAR &&
		buff[x + 5] == EMPTY_CHAR &&
		buff[x + 10] == EMPTY_CHAR &&
		buff[x + 15] == EMPTY_CHAR)
		{
			if (*index_x_start == 42)
				*index_x_start = x;
			block->w--;
		}
		x++;
	}
}

static void	set_size_height(char *buff, t_tetrimino *block, int *index_y_start)
{
	int x;

	x = 0;
	block->w = 4;
	*index_y_start = 42;
	while (x < 4)
	{
		if (buff[0 + x * 5] == EMPTY_CHAR &&
		buff[1 + x * 5] == EMPTY_CHAR &&
		buff[2 + x * 5] == EMPTY_CHAR &&
		buff[3 + x * 5] == EMPTY_CHAR)
		{
			if (*index_y_start == 42)
				*index_y_start = x;
			block->h--;
		}
		x++;
	}
}

t_tetrimino	*get_tetrimino_elem(char *buff, char block_char)
{
	t_tetrimino *to_return;
	int			index_x_start;
	int			index_y_start;
	int			i;

	i = 0;
	to_return = (t_tetrimino *)ft_memalloc(sizeof(t_tetrimino));
	if (to_return == NULL)
		return (NULL);
	set_size_width(buff, to_return, &index_x_start);
	set_size_height(buff, to_return, &index_y_start);
	to_return->array = alloc_array(to_return);
	if (to_return->array == NULL)
		return (NULL);
	while (i < to_return->h)
	{
		ft_memcpy(to_return->array[i],
		buff + (i + index_y_start) * 5 + index_x_start, to_return->w);
		index_y_start++;
		i++;
	}
	return (to_return);
}
