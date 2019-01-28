/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:29:39 by tde-jong       #+#    #+#                */
/*   Updated: 2019/01/16 13:01:36 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	if ((newlist = (t_list*)malloc(sizeof(t_list) * 1)) == NULL)
		return (NULL);
	if (content)
	{
		if ((newlist->content = (void*)malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	else
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	newlist->next = NULL;
	return (newlist);
}
