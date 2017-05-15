/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 13:00:55 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/28 14:28:06 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "colors.h"

int	bi_alias(t_shell *sh, char **args)
{
	if (ft_tablen(args) != 2)
	{
		print_error("alias must have two arguments.", NULL);
		return (1);
	}
	h_set_or_create_elem(sh->aliases, args[0], args[1]);
	if (sh->is_interactive)
	{
		ft_putstr(BOLD);
		ft_putstr(args[0]);
		ft_putstr(INIT);
		ft_putstr(" -> ");
		ft_putendl(args[1]);
	}
	return (0);
}
