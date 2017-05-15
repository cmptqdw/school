/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lslstadd_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 04:26:31 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/27 00:07:24 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lslstadd_sort(t_lslst **alst, t_lslst *new, t_param *param)
{
	t_lslst	*run;
	t_lslst	*prev;

	prev = NULL;
	if (!*alst)
		*alst = new;
	else
	{
		run = *alst;
		while (run && param->f_sort(run, new) < 0)
		{
			prev = run;
			run = run->next;
		}
		if (prev)
			prev->next = new;
		else
			*alst = new;
		new->next = run;
	}
}

int		ls_cmp(t_lslst *run, t_lslst *new)
{
	return (ft_strcmp(run->name, new->name));
}

void	select_sort(t_param *param)
{
	if (param->su)
		param->f_sort = (param->r ? &ls_cmp_sr : &ls_cmp_s);
	else if (param->t)
	{
		if (param->u)
			param->f_sort = (param->r ? &ls_cmp_tur : &ls_cmp_tu);
		else if (param->c)
			param->f_sort = (param->r ? &ls_cmp_tcr : &ls_cmp_tc);
		else if (param->uu)
			param->f_sort = (param->r ? &ls_cmp_tuur : &ls_cmp_tuu);
		else
			param->f_sort = (param->r ? &ls_cmp_tr : &ls_cmp_t);
	}
	else
		param->f_sort = (param->r ? &ls_cmp_r : &ls_cmp);
}
