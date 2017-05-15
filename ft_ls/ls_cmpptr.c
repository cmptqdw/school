/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmpptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 13:48:31 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/26 15:49:11 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_cmp_r(t_lslst *run, t_lslst *new)
{
	return (ft_strcmp(new->name, run->name));
}

int		ls_cmp_t(t_lslst *run, t_lslst *new)
{
	int		i;

	i = (new->stat.st_mtimespec.tv_sec - run->stat.st_mtimespec.tv_sec);
	if (!i)
	{
		i = new->stat.st_mtimespec.tv_nsec - run->stat.st_mtimespec.tv_nsec;
		if (!i)
			i = ls_cmp(run, new);
	}
	return (i);
}

int		ls_cmp_tr(t_lslst *run, t_lslst *new)
{
	int		i;

	i = (run->stat.st_mtimespec.tv_sec - new->stat.st_mtimespec.tv_sec);
	if (!i)
	{
		i = run->stat.st_atimespec.tv_nsec - new->stat.st_atimespec.tv_nsec;
		if (!i)
			i = ls_cmp_r(run, new);
	}
	return (i);
}

int		ls_cmp_tu(t_lslst *run, t_lslst *new)
{
	int		i;

	i = (new->stat.st_atimespec.tv_sec - run->stat.st_atimespec.tv_sec);
	if (!i)
	{
		i = new->stat.st_atimespec.tv_nsec - run->stat.st_atimespec.tv_nsec;
		if (!i)
			i = ls_cmp(run, new);
	}
	return (i);
}

int		ls_cmp_tur(t_lslst *run, t_lslst *new)
{
	int		i;

	i = run->stat.st_atimespec.tv_sec - new->stat.st_atimespec.tv_sec;
	if (!i)
	{
		i = run->stat.st_atimespec.tv_nsec - new->stat.st_atimespec.tv_nsec;
		if (!i)
			i = ls_cmp_r(run, new);
	}
	return (i);
}
