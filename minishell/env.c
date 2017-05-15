/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 21:05:32 by bdesbos           #+#    #+#             */
/*   Updated: 2016/05/16 17:08:51 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	t_lstm	*run;

	run = GINF->myenv;
	while (run)
	{
		ft_putstr(run->key);
		write(1, "=", 1);
		ft_putendl(run->value);
		run = run->next;
	}
}

void	env_msh(char **tab, int i)
{
	if (!tab[i + 1])
	{
		print_env();
		return ;
	}
	if (tab[++i] && tab[i][0] == '-' && tab[i][1] == 'i')
		(tab[++i]) ? exec_path_test(tab, i, 1) : 0;
	else
		exec_path_test(tab, i, 0);
}
