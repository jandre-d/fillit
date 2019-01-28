/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:42:11 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/24 11:28:49 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*ft_strtrim_char(char const *s, char rem)
{
	char *str;

	if (s)
	{
		str = ft_strdup(s);
		if (str == NULL)
			return (NULL);
		while (*str != '\0' && *str == rem)
		{
			str++;
		}
		str = ft_strrev(str);
		while (*str != '\0' && *str == rem)
		{
			str++;
		}
		return (ft_strrev(str));
	}
	else
	{
		return (NULL);
	}
}

static int		ft_word_count(char *str, char delim)
{
	int i;

	i = 0;
	while (*str)
	{
		while (*str != delim && *str)
			str++;
		i++;
		while (*str == delim && *str)
			str++;
	}
	return (i);
}

static int		ft_word_len_delim(char *str, char delim)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != delim)
	{
		i++;
	}
	return (i);
}

static char		**ft_create_array(char **array, char *str, char delim)
{
	int words;
	int c;

	words = ft_word_count(str, delim);
	c = 0;
	while (c < words && *str)
	{
		while (*str == delim && *str)
			str++;
		array[c] = ft_strnew(ft_word_len_delim(str, delim));
		array[c] = ft_strncpy(array[c], str, ft_word_len_delim(str, delim));
		while (*str != delim && *str)
			str++;
		c++;
	}
	array[c] = ft_strnew(0);
	array[c] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*s1;
	int		words;

	if (s)
	{
		if ((s1 = ft_strtrim_char(s, c)) == NULL)
			return (NULL);
		words = ft_word_count(s1, c);
		if ((str = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
			return (NULL);
		if ((str = ft_create_array(str, s1, c)) == NULL)
			return (NULL);
		return (str);
	}
	return (NULL);
}
