/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_shell_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 18:24:50 by bdesbos           #+#    #+#             */
/*   Updated: 2016/10/30 23:32:44 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ontheroadagain(char **av, int i, int j)
{
	int		k;
	char	*v;

	(v = ft_strdup("/minishell")) ? 0 : error(0);
	k = 0;
	if (av[i][j] == v[k] && av[i][j + 1] && av[i][j + 1] == v[k + 1]
			&& av[i][j + 2] && av[i][j + 2] == v[k + 2]
			&& av[i][j + 3] && av[i][j + 3] == v[k + 3]
			&& av[i][j + 4] && av[i][j + 4] == v[k + 4]
			&& av[i][j + 5] && av[i][j + 5] == v[k + 5]
			&& av[i][j + 6] && av[i][j + 6] == v[k + 6]
			&& av[i][j + 7] && av[i][j + 7] == v[k + 7]
			&& av[i][j + 8] && av[i][j + 8] == v[k + 8]
			&& av[i][j + 9] && av[i][j + 9] == v[k + 9])
	{
		free(v);
		return (1);
	}
	free(v);
	return (0);
}

char	*def_shell_name(char **av)
{
	int		i;
	int		j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (ontheroadagain(av, i, j))
				return (av[i]);
	}
	return ("Mr/bin/minishell");
}
