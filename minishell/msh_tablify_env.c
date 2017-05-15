/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tablify_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 01:59:19 by bdesbos           #+#    #+#             */
/*   Updated: 2016/05/16 18:02:03 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**msh_tablify_env(void)
{
	t_lstm	*run;
	int		k;
	char	**tab;

	k = 0;
	run = GINF->myenv;
	while (run)
	{
		k++;
		run = run->next;
	}
	run = GINF->myenv;
	(tab = (char**)malloc(sizeof(char*) * (k + 1))) ? 0 : error(0);
	tab[k] = NULL;
	k = 0;
	while (run)
	{
		tab[k++] = ft_strjoinkf(run->key, ft_strjoin("=", run->value));
		run = run->next;
	}
	return (tab);
}
