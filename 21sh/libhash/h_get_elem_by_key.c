/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_get_elem_by_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:24:32 by bdesbos           #+#    #+#             */
/*   Updated: 2017/02/18 19:39:48 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*h_get_elem_by_key(t_hash *hash, char *key)
{
	t_elem	*curr_elem;
	int		index;

	index = h_get_key(hash->size, key);
	curr_elem = hash->hash_tab[index];
	if (!curr_elem)
		return (NULL);
	while (curr_elem && ft_strncmp(curr_elem->key, key, ft_strlen(key)))
		curr_elem = curr_elem->next;
	if (!curr_elem)
		return (NULL);
	return (curr_elem);
}
