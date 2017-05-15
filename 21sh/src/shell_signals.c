/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:43:50 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/30 20:07:08 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	signal_sigint(int sig)
{
	static t_shell *sh = NULL;

	if (!sh)
		sh = get_shell();
	if (sh->line)
		ft_memdel((void **)&sh->line);
	ft_putendl("");
	(void)sig;
}

void		shell_signals(void)
{
	signal(SIGINT, signal_sigint);
	signal(SIGTSTP, SIG_IGN);
}
