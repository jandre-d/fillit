/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 14:21:18 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 12:33:20 by tde-jong      ########   odam.nl         */
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
		t_state *state = (t_state*)ft_memalloc(sizeof(t_state));
		system(ft_strjoin("cd input_gen && python tetriminos.py ", argv[1]));
		if (ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 26)
		{
			assert(validate_input(argv[2]) == 1);
			printf("%svalidate_input returned 1%s\n", KGRN, KNRM);
			assert(parse_input(argv[2], state) == 1);
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
		t_state *state2 = (t_state*)ft_memalloc(sizeof(t_state));
		if ((ft_strstr(argv[1], "ko") == NULL) && (ft_strstr(argv[1], "bad") == NULL))
		{
			assert(validate_input(argv[1]) == 1);
			printf("%svalidate_input returned 1%s\n", KGRN, KNRM);
			assert(parse_input(argv[1], state2) == 1);
			printf("%sparse_input returned 1%s\n", KGRN, KNRM);
			return (0);
		}
		else
		{
			assert(validate_input(argv[1]) == 0 || parse_input(argv[1], state2) == 0);
			printf("%svalidate_input returned 0%s\n", KGRN, KNRM);
			return (0);
		}
	}
	return (1);
}
