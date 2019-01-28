/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 15:51:11 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/14 16:33:32 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	end_char(char *str, int neg, int n)
{
	if (neg)
		str[1] = n + '0';
	else
		str[0] = n + '0';
}

static int	int_len(int n)
{
	if (n < 0)
		return (int_len(-n) + 1);
	if (n >= 10)
		return (int_len(n / 10) + 1);
	return (1);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = int_len(n);
	if (((str = ft_memalloc(len + 1)) == NULL))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		neg = 1;
	}
	while (n >= 10)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	end_char(str, neg, n);
	return (str);
}
