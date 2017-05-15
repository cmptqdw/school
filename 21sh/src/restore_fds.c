/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:42:56 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 17:43:03 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	restore_fds(void)
{
	static t_shell *sh = NULL;

	if (!sh)
		sh = get_shell();
	dup2(sh->save_in, 0);
	dup2(sh->save_out, 1);
	dup2(sh->save_err, 2);
}
