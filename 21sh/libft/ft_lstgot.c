/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:54:30 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/20 15:54:44 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	ft_lstgot(t_list *list, t_list *elem)
{
	while (list)
	{
		if (list == elem)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}
