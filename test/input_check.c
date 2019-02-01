/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 14:21:18 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 16:34:26 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../validate_input.c"
#include "../parse_input.c"
#include "../fillit.h"
#include <assert.h>
#include <stdio.h>


#define KGRN "\x1B[32m"
#define KNRM  "\x1B[0m"

int	main(int argc, char **argv)
{
	if (argc == 4 && ft_strcmp(argv[3], "input_gen") == 0)
	{
		t_map *map = (t_map*)ft_memalloc(sizeof(t_map));
		t_tetrimino *tet = NULL;
		system(ft_strjoin("cd input_gen && python tetriminos.py ", argv[1]));
		if (ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 26)
		{
			assert(validate_input(argv[2]) == 1);
			printf("%svalidate_input returned 1%s\n", KGRN, KNRM);
			assert(parse_input(argv[2], map) == 1);
			printf("%sparse_input returned 1%s\n", KGRN, KNRM);
		}
		else
		{
			assert(validate_input(argv[2]) == 0);
			printf("%svalidate_input returned 0%s\n", KGRN, KNRM);
		}
		return (0);
	}
	else if (argc == 2)
	{
		t_map *map2 = (t_map*)ft_memalloc(sizeof(t_map));
		t_tetrimino *tet2 = NULL;
		if ((ft_strstr(argv[1], "ko") == NULL) && (ft_strstr(argv[1], "bad") == NULL))
		{
			assert(validate_input(argv[1]) == 1);
			printf("%svalidate_input returned 1%s\n", KGRN, KNRM);
			assert(parse_input(argv[1], map2) == 1);
			printf("%sparse_input returned 1%s\n", KGRN, KNRM);
			return (0);
		}
		else
		{
			assert(validate_input(argv[1]) == 0 || parse_input(argv[1], map2) == 0);
			printf("%svalidate_input returned 0%s\n", KGRN, KNRM);
			return (0);
		}
	}
	return (1);
}
