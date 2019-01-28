/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 16:25:37 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/14 12:01:34 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char *s;

	d = dst;
	s = src;
	if (d == s)
		return (dst);
	if (d < s)
	{
		dst = ft_memcpy(d, s, len);
	}
	else
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	return (dst);
}
