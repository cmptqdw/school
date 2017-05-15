/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 21:00:06 by bdesbos           #+#    #+#             */
/*   Updated: 2016/04/16 21:03:28 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstmpush(t_lstm **alst, t_lstm *elem)
{
	t_lstm	*run;

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
