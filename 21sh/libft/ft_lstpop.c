/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:50:53 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/20 15:51:01 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **begin)
{
	t_list *elem;

	if (!begin || !*begin)
		return (NULL);
	elem = *begin;
	*begin = elem->next;
	elem->next = NULL;
	return (elem);
}
