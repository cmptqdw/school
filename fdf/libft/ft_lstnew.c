/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:02:34 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/02 20:25:40 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = NULL;
	new->next = NULL;
	new->content_size = 0;
	if (content == NULL)
		return (new);
	if (!(new->content = ft_memalloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	new->content = ft_memcpy(new->content, content, content_size - 1);
	new->content_size = content_size;
	return (new);
}
