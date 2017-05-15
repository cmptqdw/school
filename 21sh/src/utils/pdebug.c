/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdebug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:09:34 by bdesbos           #+#    #+#             */
/*   Updated: 2016/12/08 16:10:47 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	pdebug(char *str)
{
	static t_shell *sh = NULL;

	if (!sh)
		sh = get_shell();
	if (sh->is_interactive)
		ft_putendl_fd(str, sh->tout);
}
