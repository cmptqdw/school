/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lslstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 04:01:06 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/22 04:15:13 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lslst	*ft_lslstnew(char *name, size_t name_size)
{
	t_lslst *new;

	if (!(new = (t_lslst*)malloc(sizeof(t_lslst))))
		return (NULL);
	new->name = NULL;
	new->next = NULL;
	new->name_size = 0;
	if (name == NULL)
		return (new);
	if (!(new->name = ft_memalloc(name_size)))
	{
		free(new);
		return (NULL);
	}
	new->name = ft_memcpy(new->name, name, name_size - 1);
	new->name_size = name_size;
	return (new);
}
