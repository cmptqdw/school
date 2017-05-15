/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 21:48:31 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/03 18:59:29 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_path_test(char **tab, int i, int o)
{
	if (!ft_strcmp(tab[0], "echo"))
		normechoch(tab);
	else if (ft_strchr(tab[i], '/'))
	{
		if (access(tab[i], F_OK))
		{
			ft_putstr_fd("msh: no such file or directory: ", GINF->termfd);
			ft_putendl_fd(tab[i], GINF->termfd);
		}
		else if (access(tab[i], X_OK))
		{
			ft_putendl_fd("msh: permission denied, bro", GINF->termfd);
		}
		else
			msh_exec(tab[i], tab, o);
	}
	else
		path_loop(tab, i, o);
}

void	err_msg_access(int m, char *tab)
{
	if (m)
		ft_putendl_fd("You shall not pass", GINF->termfd);
	else
	{
		ft_putstr_fd("msh: command not found: ", GINF->termfd);
		ft_putendl_fd(tab, GINF->termfd);
	}
}

int		init_and_check_path(int *p)
{
	*p = 0;
	if (!GINF->path[0])
	{
		ft_putendl_fd("msh: no PATH to search", GINF->termfd);
		return (1);
	}
	return (0);
}

void	path_loop(char **tab, int i, int o)
{
	char	*fullpath;
	char	*temp;
	int		p;
	int		m;

	if ((m = init_and_check_path(&p)))
		return ;
	while (GINF->path[p])
	{
		temp = ft_strjoin("/", tab[i]);
		fullpath = ft_strjoin(GINF->path[p++], temp);
		ft_memdel((void **)&temp);
		if (!access(fullpath, F_OK))
		{
			if (!access(fullpath, X_OK))
			{
				msh_exec(fullpath, tab + i, o);
				fullpath ? free(fullpath) : 0;
				return ;
			}
			m++;
		}
		fullpath ? free(fullpath) : 0;
	}
	err_msg_access(m, tab[i]);
}

void	hub(char **tab, int i, int o)
{
	if (!ft_strcmp(tab[i], "cd"))
		cd_msh(tab + i);
	else if (!ft_strcmp(tab[i], "env"))
		env_msh(tab, i);
	else if (!ft_strcmp(tab[i], "setenv"))
		setenv_msh(tab + i);
	else if (!ft_strcmp(tab[i], "unsetenv"))
		unsetenv_loop(tab + i + 1);
	else if (!ft_strcmp(tab[i], "exit"))
	{
		if (tab[i + 1] && tab[i + 2])
			ft_putendl_fd("exit: too many args, go back to primary scho'ol",
					GINF->termfd);
		else
		{
			(tab[i + 1] && ft_strisdigit(tab[i + 1])) ?
				exit(ft_atoi(tab[i + 1])) : exit(0);
		}
	}
	else
		exec_path_test(tab, i, o);
}
