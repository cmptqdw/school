/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_np.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 23:41:24 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/13 10:55:14 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_np(t_list **alst, t_list *new)
{
	t_list	*run;

	run = *alst;
	if (new)
	{
		if (run)
		{
			while (run->next)
				run = run->next;
			run->next = new;
		}
		else
			*alst = new;
	}
}
