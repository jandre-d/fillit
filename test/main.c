/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 11:37:13 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 10:01:33 by tde-jong      ########   odam.nl         */
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
		if ((ret = system(ft_strjoin(base, ft_strjoin(ft_itoa(i), " input_gen/ttmnfile")))))
			abort();
		i++;
	}

	DIR *d;
    struct dirent *dir;
    d = opendir("input_example");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
			if ((ret = system(ft_strjoin(base, ft_strjoin(ft_itoa(i), " input_gen/ttmnfile")))))
			abort();
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
	return (0);
}
