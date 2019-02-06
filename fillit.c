/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 15:55:14 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/06 11:38:00 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "input.h"
#include "solver.h"

int	get_input_block_count(t_tetrimino *list)
{
	int			block_count;
	t_tetrimino *lst;

	block_count = 0;
	lst = list;
	while (lst != NULL)
	{
		block_count += 4;
		lst = lst->next;
	}
	return (block_count);
}

int	quit(char *msg)
{
	ft_putendl(msg);
	return (1);
}

int	main(int argc, char **argv)
{
	t_tetrimino *list;
	t_map		*result;
	int			fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 1)
			return (quit("error"));
		list = get_tetriminio_list(fd);
		if (list == NULL)
			return (quit("error"));
		result = solve(list);
		if (result == NULL)
			return (quit("error"));
		print_map(result);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" input_file\n");
	}
	return (0);
}
