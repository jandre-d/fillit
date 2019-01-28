/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 16:55:43 by tde-jong      #+#    #+#                 */
/*   Updated: 2019/01/10 16:55:44 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*fresh;

	fresh = malloc(size);
	if (fresh == NULL)
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}
