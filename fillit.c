/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 15:55:14 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/06 14:49:14 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "input.h"
#include "solver.h"
#include "map.h"

int	quit(char *msg)
{
	ft_putendl(msg);
	return (1);
}

void	do_it(char *filename)
{
	t_tetrimino *list;
	t_map		*result;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (quit("error"));
	list = get_tetriminio_list(fd);
	if (list == NULL)
		return (quit("error"));
	result = solve(list);
	if (result == NULL)
		return (quit("error"));
	print_map(result);
	free_alles(list, result);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		do_it(argv[1]);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" input_file\n");
	}
	return (0);
}
