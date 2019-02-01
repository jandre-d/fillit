/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 11:37:13 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 10:08:34 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>

#include <dirent.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	char	*base;
	int		ret;

	i = 0;
	base = "./input_check ";
	while (i < 28)
	{
		if ((ret = system(ft_strjoin(base, ft_strjoin(ft_itoa(i), " input_gen/ttmnfile input_gen")))))
			abort();
		i++;
	}
	sleep(10);
	DIR *d;
    struct dirent *dir;
    d = opendir("input_example");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
			if (dir->d_name != ".." && dir->d_name != ".")
				if ((ret = system(ft_strjoin(ft_strjoin(base, " "), dir->d_name))))
					abort();
        }
        closedir(d);
    }
	return (0);
}
