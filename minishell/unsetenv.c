/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 07:33:27 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/02 20:42:58 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unsetenv_loop(char **tab)
{
	int		i;

	i = -1;
	if (!tab[0])
		ft_putendl_fd("error: gimme something to unset ffs", GINF->termfd);
	else
		while (tab[++i])
			unsetenv_msh(tab[i]);
}

void	cleanall(t_lstm *run, char *tmp)
{
	checkandmajwstruct(run->key, tmp);
	ft_strdel(&tmp);
	free(run->key);
	free(run->value);
	free(run);
}

void	norm_equloop(t_lstm *run, t_lstm *prev, int *k, char *name)
{
	char *tmp;

	while (run)
	{
		if (ft_strequ(run->key, name))
		{
			(*k)++;
			if (run != prev)
				prev->next = run->next;
			else
			{
				GINF->myenv = run->next;
				prev = run->next;
			}
			tmp = ft_strnew(0);
			cleanall(run, tmp);
			prev ? run = prev->next : 0;
			(prev == GINF->myenv) ? run = prev : 0;
		}
		else
		{
			prev = run;
			run = run->next;
		}
	}
}

int		unsetenv_msh(char *name)
{
	t_lstm	*run;
	t_lstm	*prev;
	int		k;

	k = 0;
	run = GINF->myenv;
	prev = run;
	norm_equloop(run, prev, &k, name);
	ft_putnbr_fd(k, GINF->termfd);
	ft_putstr_fd(" key ", GINF->termfd);
	ft_putstr_fd(name, GINF->termfd);
	ft_putstr_fd(" blackholed of env. I ", GINF->termfd);
	ft_putendl_fd("honestly think you ought to sit down calmly", GINF->termfd);
	return (k);
}
