/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 18:50:52 by bdesbos           #+#    #+#             */
/*   Updated: 2016/04/10 22:41:59 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	prepare_and_call(char **av, t_param *param, int ac)
{
	t_lslst		*alldir;
	t_lslst		*deb;
	DIR			*dir;

	alldir = files_and_errors(av, param, ac);
	deb = alldir;
	while (alldir)
	{
		if ((dir = opendir(alldir->name)))
			recread(dir, alldir->name, param);
		else
			ls_error(alldir->name);
		alldir = alldir->next;
		alldir ? write(1, "\n", 1) : 0;
	}
	lslst_free(deb);
}

int		main(int ac, char **av)
{
	t_param		*param;
	int			i;

	i = 1;
	(param = (t_param*)malloc(sizeof(t_param))) ? 0 : ls_malloc_error();
	init_param(param);
	while (--ac && av[i][0] == '-' && av[i][1] && (av[i][1] != '-' || av[i][2]))
	{
		check_params(av[i], param);
		i++;
	}
	if (av[i] && av[i][1] && av[i][1] == '-')
	{
		i++;
		ac--;
	}
	ac > 1 ? param->multiav = 1 : 0;
	if (ac == 0)
	{
		!opendir(".") ? ls_error(".") : 0;
		(!param->d) ? recread(opendir("."), ft_strdup("."), param) : dpe(param);
	}
	else
		prepare_and_call(&av[i], param, ac);
	return (0);
}
