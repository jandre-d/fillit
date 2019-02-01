/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 14:21:18 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 10:36:08 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../validate_input.c"
#include "../parse_input.c"
#include "../fillit.h"
#include <assert.h>


#define KGRN "\x1B[32m"

int	main(int argc, char **argv)
{
	if (argc == 4 && ft_strcmp(argv[3], "input_gen") == 0)
	{
		t_state *state = (t_state*)ft_memalloc(sizeof(t_state));
		system(ft_strjoin("cd input_gen && python tetriminos.py ", argv[1]));
		if (ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 26)
		{
			assert(validate_input(argv[2]) == 1);
			printf("%svalidate_input returned 1\n", KGRN);
			assert(parse_input(argv[2], state) == 1);
			printf("%sparse_input returned 1\n", KGRN);
		}
		else
		{
			assert(validate_input(argv[2]) == 0);
			printf("%svalidate_input returned 0\n", KGRN);
		}
		return (0);
	}
	else if (argc == 3)
	{
		t_state *state = (t_state*)ft_memalloc(sizeof(t_state));
		if (ft_strstr(argv[2], "ko") == NULL && ft_strstr(argv[2], "bad") == NULL)
		{
			assert(validate_input(argv[2]) == 1);
			printf("%svalidate_input returned 1\n", KGRN);
			assert(parse_input(argv[2], state) == 1);
			printf("%sparse_input returned 1\n", KGRN);
		}
		else
		{
			assert(validate_input(argv[2]) == 0);
			printf("%svalidate_input returned 0\n", KGRN);
			assert(parse_input(argv[2], state) == 0);
			printf("%sparse_input returned 0\n", KGRN);
		}
	}
	return (1);
}
