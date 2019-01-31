/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 11:37:13 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/31 18:38:32 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>

int	main(void)
{
	int		i;
	char	*base;
	int		ret;

	i = 0;
	base = "./input_check ";
	while (i < 28)
	{
		if ((ret = system(ft_strjoin(base, ft_itoa(i)))))
			abort();
		i++;
	}
	return (0);
}
