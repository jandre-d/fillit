/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 11:56:18 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/04 17:38:48 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*
** count the amount of adjacent blocks to the block at index.
** search up-down-left-right respectively
*/

static int	get_adjacent_blocks_count(char *buff, int index)
{
	int x;

	x = 0;
	if (index > 5 && buff[index - 5] == INPUT_BLOCK_CHAR)
		x++;
	if (index < 14 && buff[index + 5] == INPUT_BLOCK_CHAR)
		x++;
	if (index % 5 > 0 && buff[index - 1] == INPUT_BLOCK_CHAR)
		x++;
	if (index % 5 < 4 && buff[index + 1] == INPUT_BLOCK_CHAR)
		x++;
	return (x);
}

static int	is_valid_block(char *buff)
{
	int x;
	int touching_sides;

	x = 0;
	touching_sides = 0;
	if (buff[4] != '\n' || buff[9] != '\n' ||
	buff[14] != '\n' || buff[19] != '\n')
		return (0);
	while (x < 20)
	{
		if (buff[x] != EMPTY_CHAR && buff[x] != INPUT_BLOCK_CHAR)
			return (0);
		if (buff[x] == INPUT_BLOCK_CHAR)
			touching_sides += get_adjacent_blocks_count(buff, x);
		if (x == 3 || x == 8 || x == 13 || x == 18)
			x += 2;
		else
			x++;
	}
	if (touching_sides == 6 || touching_sides == 8)
		return (1);
	return (0);
}

/*
** as a reference, one tetrimino/block read of 20 character would look like this
** 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19
** .  #  .  .  \n #  #  #  .  \n .  .  .  .  \n .  .  .  .  \n
*/

t_tetrimino	*get_tetriminio_list(int fd)
{
	char		buff[21];
	char		block_char;
	ssize_t		buff_usage;
	ssize_t		prev_buff_usage;
	t_tetrimino *list;

	block_char = 'a';
	buff_usage = read(fd, buff, 21);
	list = NULL;
	while (buff_usage >= 20)
	{
		if ((buff_usage == 21 && buff[20] != '\n') ||
		is_valid_block(buff) == 0 || block_char > 'z')
			return (NULL);
		if (list == NULL)
			list = get_tetrimino_elem(buff, block_char);
		else
			list->next = get_tetrimino_elem(buff, block_char);
		prev_buff_usage = buff_usage;
		buff_usage = read(fd, buff, 21);
		block_char++;
	}
	if (buff_usage == 0 && prev_buff_usage == 20)
		return (list);
	return (NULL);
}
