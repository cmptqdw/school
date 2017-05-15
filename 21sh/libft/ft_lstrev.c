/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:53:28 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/20 15:53:43 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list **begin)
{
	t_list *new;
	t_list *curr;
	t_list *next;

	if (!begin || !(curr = *begin))
		return (NULL);
	new = NULL;
	while (curr)
	{
		next = curr->next;
		ft_lstadd(&new, curr);
		curr = next;
	}
	return (*begin = new);
}
