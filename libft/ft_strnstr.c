/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:36:31 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/15 17:52:39 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		try;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	try = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			if (needle[++j] == '\0')
				return ((char *)(haystack + i + 1 - ft_strlen(needle)));
		}
		else
		{
			j = 0;
			i = try - 1;
			try++;
		}
		i++;
	}
	return (NULL);
}
