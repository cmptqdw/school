/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmpsptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:32:31 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/26 21:21:39 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_cmp_s(t_lslst *run, t_lslst *new)
{
	int		i;

	i = new->stat.st_size - run->stat.st_size;
	return (i ? i : ls_cmp(run, new));
}

int		ls_cmp_sr(t_lslst *run, t_lslst *new)
{
	int		i;

	i = run->stat.st_size - new->stat.st_size;
	return (i ? i : ls_cmp_r(run, new));
}

int		ls_cmp_tc(t_lslst *run, t_lslst *new)
{
	int		i;

	i = (new->stat.st_ctimespec.tv_sec - run->stat.st_ctimespec.tv_sec);
	if (!i)
	{
		i = new->stat.st_ctimespec.tv_nsec - run->stat.st_ctimespec.tv_nsec;
		if (!i)
			i = ls_cmp(run, new);
	}
	return (i);
}

int		ls_cmp_tcr(t_lslst *run, t_lslst *new)
{
	int		i;

	i = run->stat.st_ctimespec.tv_sec - new->stat.st_ctimespec.tv_sec;
	if (!i)
	{
		i = run->stat.st_ctimespec.tv_nsec - new->stat.st_ctimespec.tv_nsec;
		if (!i)
			i = ls_cmp_r(run, new);
	}
	return (i);
}
