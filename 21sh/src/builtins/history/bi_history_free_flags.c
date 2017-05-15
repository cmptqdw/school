/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_free_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:54:50 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 19:55:01 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bi_histo	*bi_history_free_flags(t_bi_histo *first)
{
	t_bi_histo *tmp;

	while (first)
	{
		tmp = first;
		first = first->next;
		if ((tmp->flag == 's' || tmp->flag == 'p') && tmp->arg)
			ft_memdel((void **)&(tmp->arg));
		free(tmp);
	}
	return (NULL);
}
