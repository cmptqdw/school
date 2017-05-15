/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 06:42:18 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/03 18:45:51 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		norm_setenv_msh(char **tab, t_lstm *run)
{
	if (!tab[3] || tab[3][0] == '0')
	{
		if (*run->value)
			(run->value = ft_strjoinff(run->value, ft_strjoin(":", tab[2]))) ?
				0 : error(0);
		else
			(run->value = ft_strjoinf(run->value, tab[2])) ? 0 : error(0);
	}
	else if (tab[3][0] == '1')
	{
		run->value ? free(run->value) : 0;
		(run->value = ft_strdup(tab[2])) ? 0 : error(0);
	}
	else
	{
		ft_putendl_fd("warning: not binary overwrite's option", GINF->termfd);
		return (-1);
	}
	run ? checkandmajstruct(run, NULL) : 0;
	return (0);
}

void	normechoch(char **tab)
{
	int		i;

	i = 0;
	while (tab[++i])
	{
		ft_putstr_fd(tab[i], GINF->termfd);
		tab[i + 1] ? ft_putstr_fd(" ", GINF->termfd) : 0;
	}
	ft_putstr_fd("\n", GINF->termfd);
}

int		setenv_msh(char **tab)
{
	t_lstm	*run;

	run = GINF->myenv;
	if (!tab[1] || !tab[2])
	{
		ft_putendl_fd("need at least 2 param (key, value, over)", GINF->termfd);
		return (-1);
	}
	while (run && !ft_strequ(run->key, tab[1]))
		run = run->next;
	if (!run)
	{
		lstmadd(&GINF->myenv, lstmnew(tab[1], (tab[2] ? tab[2] :
						ft_strnew(0))));
		checkandmajwstruct(tab[1], tab[2]);
	}
	else if (!tab[2])
	{
		free(run->value);
		run->value = ft_strnew(0);
	}
	else
		return (norm_setenv_msh(tab, run));
	return (0);
}
