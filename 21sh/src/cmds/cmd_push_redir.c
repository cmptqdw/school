/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:12:57 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/27 21:22:58 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	cmd_push_redir_end(t_redir **redirp, t_redir *new)
{
	t_redir *current;

	if (!(current = *redirp))
	{
		*redirp = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}

void	cmd_push_redir_front(t_redir **redirp, t_redir *new)
{
	new->next = *redirp;
	*redirp = new;
}
