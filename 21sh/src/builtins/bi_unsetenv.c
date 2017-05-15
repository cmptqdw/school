/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:34:04 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/31 20:34:09 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	u_msg(char *key, int n)
{
	ft_putstr(key);
	n == 0 ? ft_putendl(" key not found") : 0;
	n == 1 ? ft_putendl(" has been deleted") : 0;
}

int			bi_unsetenv(t_shell *sh, char **args)
{
	int	i;

	i = 0;
	if (!args[0])
		ft_putendl("setenv: usage: [name ...]");
	while (args[i])
	{
		h_delete_elem(sh->env, args[i]) ? u_msg(args[i], 1) : u_msg(args[i], 0);
		if (!ft_strcmp(args[i], "PATH"))
			shell_update_bins(sh);
		i++;
	}
	sh->env_update = 1;
	return (0);
}
