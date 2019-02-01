/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 08:12:21 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 15:50:47 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate_input.h"

static int	count_blocks(char *line, int *blocks)
{
	while (*line)
	{
		if (*line == '#')
			(*blocks)++;
		else if (!(*line == '.'))
			return (0);
		line++;
	}
	return (1);
}

static int	check_line(char *line, int *in_progress, int *tetriminos)
{
	static int blocks;
	static int ln;

	if (((ln + 1) % 5 == 0))
	{
		if (!(ft_strlen(line) == 0) || (blocks != 4))
			return (0);
		blocks = 0;
	}
	else
	{
		if ((*tetriminos == 27 - 1) || !(ft_strlen(line) == 4) ||
				!count_blocks(line, &blocks))
			return (0);
		*in_progress = 1;
		if (((ln + 2) % 5 == 0))
		{
			if (blocks != 4)
				return (0);
			(*tetriminos)++;
			*in_progress = 0;
		}
	}
	ln++;
	return (1);
}

int			validate_input(char *filename)
{
	int		ret;
	int		fd;
	char	*line;
	int		in_progress;
	int		tetriminos;

	tetriminos = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	in_progress = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (!check_line(line, &in_progress, &tetriminos))
			return (0);
	}
	if (in_progress || ret == -1 || tetriminos < 1)
		return (0);
	close(fd);
	return (1);
}
