/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 15:55:14 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/04 14:11:24 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_input_block_count(t_tetrimino *list)
{
	int			block_count;
	t_tetrimino *lst;
	int			x;
	int			y;

	block_count = 0;
	lst = list;
	while (lst != NULL)
	{
		y = 0;
		while (y < lst->h)
		{
			x = 0;
			while (x < lst->w)
			{
				if (lst->array[y][x] == '#')
					block_count++;
				x++;
			}
			y++;
		}
		lst = lst->next;
	}
	return (block_count);
}

int	quit(char *msg)
{
	ft_putstr(msg);
	return (0);
}

int	main(int argc, char **argv)
{
	t_tetrimino *list;
	t_map		*result;

	if (argc == 2)
	{
		list = get_tetriminio_list();
		if (list == NULL)
			return (quit("ERROR"));
		result = solve(list);
		if (result == NULL)
			return (quit("ERROR"));
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" source_file\n");
	}
	return (0);
}
