/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 20:49:20 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 19:53:28 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lstp	*lstpnew(int x, int y, int z)
{
	t_lstp	*out;

	(!(out = (t_lstp*)malloc(sizeof(t_lstp)))) ? fdf_error(1) : 0;
	out->x = x;
	out->y = y;
	out->z = z;
	out->next = NULL;
	return (out);
}

void	lstppush(t_lstp **alst, t_lstp *elem)
{
	t_lstp	*run;

	run = *alst;
	if (elem)
	{
		if (run)
		{
			while (run->next)
				run = run->next;
			run->next = elem;
		}
		else
			*alst = elem;
	}
}

void	lstpfree(t_lstp *alst)
{
	if (alst)
	{
		lstpfree(alst->next);
		free(alst);
	}
}
