/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 14:21:18 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 10:20:24 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../validate_input.c"
#include "../parse_input.c"
#include "../fillit.h"
#include <assert.h>

int	main(int argc, char **argv)
{
	if (argc == 4 && ft_strcmp(argv[3], "input_gen") == 0)
	{
		t_state *state = (t_state*)ft_memalloc(sizeof(t_state));
		system(ft_strjoin("cd input_gen && python tetriminos.py ", argv[1]));
		if (ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 26)
		{
			assert(validate_input(argv[2]) == 1);
			assert(parse_input(argv[2], state) == 1);
			ft_putendl("input is valid, this is correct");
		}
		else
		{
			assert(validate_input(argv[2]) == 0);
			ft_putendl("input is invalid, this is correct");
		}
		return (0);
	}
	else if (argc == 3)
	{
		t_state *state = (t_state*)ft_memalloc(sizeof(t_state));
		if (ft_strstr(argv[2], "ko") == NULL && ft_strstr(argv[2], "bad") == NULL)
		{
			assert(validate_input(argv[2]) == 1);
			assert(parse_input(argv[2], state) == 1);
		}
		else
		{
			assert(validate_input(argv[2]) == 0);
			assert(parse_input(argv[2], state) == 0);
		}
	}
	return (1);
}
