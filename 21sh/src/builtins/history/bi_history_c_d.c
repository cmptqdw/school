/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_c_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:45:42 by bdesbos           #+#    #+#             */
/*   Updated: 2017/02/19 16:48:18 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	bi_histo_del_one_entry(t_histo *entry, t_shell *sh)
{
	t_histo *tmp;

	tmp = entry;
	if (entry->prev)
		entry->prev->next = entry->next ? entry->next : NULL;
	if (entry->next)
		entry->next->prev = entry->prev ? entry->prev : NULL;
	if (tmp->value)
		free(tmp->value);
	ft_memdel((void **)&tmp);
	sh->nb_histo--;
}

int		bi_history_c(t_bi_histo *current, t_shell *sh)
{
	unload_histo(&(sh->histo));
	sh->nb_histo = 0;
	(void)current;
	return (0);
}

int		bi_history_d(t_bi_histo *current, t_shell *sh)
{
	bi_histo_del_one_entry(bi_history_get_pos(sh->histo, current->offset), sh);
	return (0);
}
