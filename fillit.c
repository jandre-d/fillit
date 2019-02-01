/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelmer <jelmer@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 15:55:14 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 09:46:41 by jelmer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_byte	get_initial_size_sqrt(int block_count)
{
	int a;

	a = 0;
	while (a * a < block_count)
	{
		a++;
	}
	return (a);
}

int	get_input_block_count(t_tetrimino *list)
{
	int			block_count;
	t_tetrimino *lst;
	t_byte		i;
	t_byte		j;

	block_count = 0;
	lst = list;
	while (lst != NULL)
	{
		i = 0;
		while (j < lst->h)
		{
			j = 0;
			while (i < lst->w)
			{
				if (lst->array[i][j] == '#')
					block_count++;
				j++;
			}
			i++;
		}
		lst = lst->next;
	}
	return (block_count);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{

	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" source_file\n");
	}
	return (0);
}
