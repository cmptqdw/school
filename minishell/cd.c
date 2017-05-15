/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:27:26 by bdesbos           #+#    #+#             */
/*   Updated: 2016/05/24 16:04:14 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	maj_lstm(void)
{
	t_lstm	*run;

	run = GINF->myenv;
	while (run)
	{
		if (ft_strequ(run->key, "PWD"))
		{
			run->value ? free(run->value) : 0;
			run->value = ft_strdup(GINF->pwd);
		}
		else if (ft_strequ(run->key, "OLDPWD"))
		{
			run->value ? free(run->value) : 0;
			run->value = ft_strdup(GINF->oldpwd);
		}
		run = run->next;
	}
}

void	cd_dontneedhome(void)
{
	if (ft_strcmp(GINF->pwd, GINF->oldpwd))
	{
		free(GINF->oldpwd);
		GINF->oldpwd = ft_strdup(GINF->pwd);
	}
	free(GINF->pwd);
	GINF->pwd = NULL;
	GINF->pwd = getcwd(GINF->pwd, 0);
}

void	cd_msh(char **tab)
{
	char	*path;

	path = NULL;
	if (!tab[1] || ft_strequ(tab[1], "~"))
		(path = ft_strdup(GINF->home)) ? 0 :
			ft_putendl_fd("home sweet home not defined", 2);
	else if (tab[1][0] == '~')
	{
		path = ft_strjoin(GINF->home, tab[1] + 1);
		ft_putendl(path);
	}
	else if (ft_strequ(tab[1], "-"))
		path = ft_strdup(GINF->oldpwd);
	else
		path = ((tab[1][0] == '/') ? ft_strdup(tab[1]) :
				ft_strjoinff(getcwd(path, 0), ft_strjoin("/", tab[1])));
	if (path && chdir(path) == -1)
		ft_putendl_fd("I'm sorry Dave, I'm afraid I can't access that",
				GINF->termfd);
	else
	{
		cd_dontneedhome();
		maj_lstm();
	}
	path ? free(path) : 0;
}
