/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:39:31 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/29 18:09:44 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			stock_params_bbbis(char av, t_param *param)
{
	int		out;

	out = 1;
	if (av == 'A')
	{
		!param->a ? (param->au = out) : 0;
		param->a = 1;
		out--;
	}
	else if (av == 'd')
		param->d = out--;
	return (out);
}

int			stock_params_bbis(char av, t_param *param)
{
	int		out;

	out = 1;
	if (av == 'c')
	{
		param->u = 0;
		param->uu = 0;
		param->c = out--;
	}
	else if (av == 'U')
	{
		param->uu = out--;
		param->u = 0;
		param->c = 0;
	}
	else if (av == 's')
		param->s = out--;
	else if (av == 'S')
		param->su = out--;
	else if (av == 'f')
		param->f = out--;
	else
		out = stock_params_bbbis(av, param);
	return (out);
}

int			stock_params_bis(char av, t_param *param)
{
	int		out;

	out = 1;
	if (av == 'r')
		param->r = out--;
	else if (av == 'R')
		param->ru = out--;
	else if (av == 'u')
	{
		param->u = out--;
		param->uu = 0;
		param->c = 0;
	}
	else if (av == 'g' || av == 'o')
	{
		av == 'g' ? param->g = out-- : 0;
		av == 'o' ? param->o = out-- : 0;
		param->l = 1;
		param->un = 0;
	}
	else if (av == 'G')
		param->gu = out--;
	else
		out = stock_params_bbis(av, param);
	return (out ? 0 : 1);
}

void		check_params(char *av, t_param *param)
{
	while (*++av)
	{
		if (*av == 'l')
		{
			param->l = 1;
			param->un = 0;
		}
		else if (*av == '1')
		{
			param->un = 1;
			param->l = 0;
			param->g = 0;
			param->o = 0;
		}
		else if (*av == 'a')
		{
			param->a = 1;
			param->au ? param->au = 0 : 0;
		}
		else if (*av == 't')
			param->t = 1;
		else if (!stock_params_bis(*av, param))
			param_error(*av);
		select_sort(param);
	}
}

void		init_param(t_param *param)
{
	param->l = 0;
	param->ru = 0;
	param->a = 0;
	param->r = 0;
	param->t = 0;
	param->un = 0;
	param->u = 0;
	param->uu = 0;
	param->f = 0;
	param->g = 0;
	param->d = 0;
	param->gu = 0;
	param->s = 0;
	param->su = 0;
	param->c = 0;
	param->o = 0;
	param->au = 0;
	time(&param->tepoch);
	param->multiav = 0;
	param->f_sort = &ls_cmp;
}
