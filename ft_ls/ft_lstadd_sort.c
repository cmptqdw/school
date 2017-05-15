/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 03:20:18 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/26 11:26:41 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstadd_sort(t_list **alst, t_list *new)
{
	t_list	*run;
	t_list	*prev;

	prev = NULL;
	if (!*alst)
		*alst = new;
	else
	{
		run = *alst;
		while (run && ft_strcmp(run->content, new->content) < 0)
		{
			prev = run;
			run = run->next;
		}
		if (prev)
			prev->next = new;
		else
			*alst = new;
		new->next = run;
	}
}
