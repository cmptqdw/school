/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmpsptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:32:31 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/27 00:11:29 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_cmp_tuu(t_lslst *run, t_lslst *new)
{
	int		i;

	i = (new->stat.st_birthtimespec.tv_sec - run->stat.st_birthtimespec.tv_sec);
	if (!i)
	{
		i = new->stat.st_birthtimespec.tv_nsec -
			run->stat.st_birthtimespec.tv_nsec;
		if (!i)
			i = ls_cmp(run, new);
	}
	return (i);
}

int		ls_cmp_tuur(t_lslst *run, t_lslst *new)
{
	int		i;

	i = run->stat.st_birthtimespec.tv_sec - new->stat.st_birthtimespec.tv_sec;
	if (!i)
	{
		i = run->stat.st_birthtimespec.tv_nsec -
			new->stat.st_birthtimespec.tv_nsec;
		if (!i)
			i = ls_cmp_r(run, new);
	}
	return (i);
}
