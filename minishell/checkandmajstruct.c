/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkandmajwstruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:59:02 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/03 18:41:32 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	next_norm(LM *elem, char *msh)
{
	if (ft_strequ(elem->key, "SHLVL"))
	{
		GINF->shlvl = (msh ? ft_itoa(1 + ft_atoi(elem->value)) : elem->key);
		msh ? free(elem->value) : 0;
		msh ? elem->value = GINF->shlvl : 0;
	}
	else if (ft_strequ(elem->key, "SHELL"))
	{
		msh ? free(elem->value) : 0;
		msh ? elem->value = ft_strdup(msh) : 0;
		GINF->shell = elem->value;
	}
	else if (ft_strequ(elem->key, "HOME"))
		GINF->home = elem->value;
}

void	checkandmajstruct(LM *elem, char *msh)
{
	if (ft_strequ(elem->key, "LOGNAME"))
		GINF->logname = elem->value;
	else if (ft_strequ(elem->key, "PATH"))
	{
		GINF->path ? ft_tabfree(GINF->path) : 0;
		(GINF->path = ft_strsplit(elem->value, ':')) ? 0 : error(0);
	}
	else if (ft_strequ(elem->key, "PWD"))
	{
		GINF->pwd ? ft_strdel(&GINF->pwd) : 0;
		GINF->pwd = ft_strdup(elem->value);
	}
	else if (ft_strequ(elem->key, "OLDPWD"))
	{
		GINF->oldpwd ? ft_strdel(&GINF->pwd) : 0;
		GINF->oldpwd = ft_strdup(elem->value);
	}
	else
		next_norm(elem, msh);
}

void	norm_wmaj(char *key, char *value)
{
	if (ft_strequ(key, "SHLVL"))
		GINF->shlvl = ft_strdup(value);
	else if (ft_strequ(key, "SHELL"))
		GINF->shell = value;
	else if (ft_strequ(key, "HOME"))
		GINF->home = value;
}

void	checkandmajwstruct(char *key, char *value)
{
	if (ft_strequ(key, "LOGNAME"))
		GINF->logname = value;
	else if (ft_strequ(key, "PATH"))
	{
		GINF->path ? ft_tabfree(GINF->path) : 0;
		(GINF->path = ft_strsplit(value, ':')) ? 0 : error(0);
	}
	else if (ft_strequ(key, "PWD"))
	{
		GINF->pwd ? ft_strdel(&GINF->pwd) : 0;
		GINF->pwd = ft_strdup(value);
	}
	else if (ft_strequ(key, "OLDPWD"))
	{
		GINF->oldpwd ? ft_strdel(&GINF->oldpwd) : 0;
		GINF->oldpwd = ft_strdup(value);
	}
	else
		norm_wmaj(key, value);
}
