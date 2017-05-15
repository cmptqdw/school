/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:44:58 by bdesbos           #+#    #+#             */
/*   Updated: 2016/12/12 19:42:28 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_minetcpath(void)
{
	char	*buf;
	int		ret;
	char	*minipath;

	minipath = NULL;
	if ((ret = open("/etc/paths", O_RDONLY)) > 0)
	{
		((gnl(ret, &buf)) > 0) ? minipath = ft_strdup(buf) : 0;
		free(buf);
		while ((gnl(ret, &buf) > 0))
		{
			minipath = ft_strjoinff(minipath, ft_strjoinkf(":", buf));
		}
	}
	(ret > 0) ? close(ret) : 0;
	lstmpush(&GINF->myenv, lstmnew("PATH", minipath));
	if (minipath)
	{
		GINF->path = ft_strsplit(minipath, ':');
		free(minipath);
	}
}

void	hailtothenorme(char *msh)
{
	if (!GINF->oldpwd)
	{
		GINF->oldpwd = ft_strdup(GINF->pwd);
		lstmpush(&GINF->myenv, lstmnew("OLDPWD", GINF->oldpwd));
	}
	!GINF->path ? get_minetcpath() : 0;
	if (!GINF->shell)
	{
		GINF->shell = ft_strdup(msh);
		lstmpush(&GINF->myenv, lstmnew("SHELL", GINF->shell));
	}
	if (!GINF->home)
		GINF->home = ft_strdup("/Users/bdesbos");
}

void	checkminienv(char *msh)
{
	char	*buf;

	buf = NULL;
	if (!GINF->shlvl)
	{
		GINF->shlvl = ft_strdup("1");
		lstmpush(&GINF->myenv, lstmnew("SHLVL", GINF->shlvl));
	}
	if (!GINF->logname)
	{
		GINF->logname = (getpwuid(getuid()))->pw_name;
		lstmpush(&GINF->myenv, lstmnew("LOGNAME", GINF->logname));
	}
	if (!GINF->pwd)
	{
		GINF->pwd = getcwd(buf, 0);
		lstmpush(&GINF->myenv, lstmnew("PWD", GINF->pwd));
	}
	hailtothenorme(msh);
}

void	init(char **env, char *msh)
{
	int		i;
	int		k;
	t_lstm	*elem;
	char	**tmp;
	char	*t;

	i = -1;
	k = 0;
	t = ttyname(0);
	GINF->termfd = open(t, O_WRONLY);
	ft_memdel((void **)&t);
	while (env[++i])
	{
		tmp = msh_split_eq(env[i]);
		elem = lstmnew(tmp[0], tmp[1]);
		lstmpush(&GINF->myenv, elem);
		ft_tabfree(tmp);
		checkandmajstruct(elem, msh);
	}
	checkminienv(msh);
	msh_signal();
}
