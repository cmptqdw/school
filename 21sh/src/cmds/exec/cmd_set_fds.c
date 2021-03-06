/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 04:03:30 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/27 21:33:19 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static int	get_fd_for(t_redir *current, int from, int links)
{
	while (current)
	{
		if (current->from == from)
		{
			if ((current->rtype == W_LINK || current->rtype == R_LINK) && links)
				return (current->to);
			else if ((current->rtype != W_LINK && current->rtype != R_LINK) &&
			!links)
				return (current->to);
		}
		current = current->next;
	}
	return (-1);
}

void		cmd_set_fds(t_redir *redirs, int links)
{
	int fd;
	int i;

	i = -1;
	while (++i < 3)
	{
		if ((fd = get_fd_for(redirs, i, links)) != -1)
		{
			close(i);
			if (fd != -3)
				dup(fd);
		}
	}
	if (!links)
		cmd_set_fds(redirs, 1);
}
