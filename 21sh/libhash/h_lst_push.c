/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_lst_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:25:40 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 17:25:42 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*lst_push_elem(t_elem **entry, char *key, char *value)
{
	t_elem	*curr_elem;

	if (!*entry)
		return ((*entry = lst_new_elem(key, value)));
	curr_elem = *entry;
	while (curr_elem->next)
		curr_elem = curr_elem->next;
	return ((curr_elem->next = lst_new_elem(key, value)));
}
