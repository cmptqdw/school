/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 22:55:27 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/30 18:29:48 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*change_lpath(char *rlbuf, char *av)
{
	int		k;
	int		j;
	char	*rev;

	j = 0;
	k = 0;
	rev = ft_strnew(255);
	while (av[j])
		j++;
	j--;
	while (av[j] && av[j] != '/')
		j--;
	while (av[j])
		rev[k++] = av[j--];
	return (ft_strjoinff(ft_strrev(rev), rlbuf));
}

void	add_to_argfl(t_lslst **argfl, t_lslst *afl, t_param *param)
{
	afl->grp = getgrgid(afl->stat.st_gid);
	afl->spwd = getpwuid(afl->stat.st_uid);
	ft_lslstadd_sort(argfl, afl, param);
}

int		add_to_alldir(char *av, t_lslst **alldir, t_param *param)
{
	t_lslst			*lfl;
	char			*rlbuf;
	int				i;

	i = 0;
	(readlink(av, (rlbuf = ft_strnew(255)), 255) == -1) ? ls_error(av) : 0;
	rlbuf = change_lpath(rlbuf, av);
	(lfl = ft_lslstnew(rlbuf, ft_strlen(rlbuf) + 1)) ? 0 : ls_malloc_error();
	if (!lstat(rlbuf, &lfl->stat) && S_ISDIR(lfl->stat.st_mode))
	{
		ft_lslstadd_sort(alldir, lfl, param);
		i++;
	}
	else
		lslst_free(lfl);
	free(rlbuf);
	return (i);
}

void	f_a_error(t_lslst *argfl, t_param *param, t_lslst *alldir)
{
	t_lslst			*deb;

	if (argfl)
	{
		deb = argfl;
		while (argfl)
		{
			param->l ? print_file(argfl, NULL, param) :
				ft_putendl(argfl->name);
			argfl = argfl->next;
		}
		param->multiav && alldir ? write(1, "\n", 1) : 0;
		lslst_free(deb);
	}
}

t_lslst	*files_and_errors(char **av, t_param *param, int ac)
{
	t_list			*errlst;
	t_lslst			*argfl;
	t_lslst			*afl;
	t_lslst			*alldir;

	errlst = NULL;
	argfl = NULL;
	alldir = NULL;
	while (ac--)
	{
		(afl = ft_lslstnew(*av, ft_strlen(*av) + 1)) ? 0 : ls_malloc_error();
		if (lstat(*av, &afl->stat))
			ft_lstadd_sort(&errlst, ft_lstnew(*av, ft_strlen(*av) + 1));
		else if (S_ISDIR(afl->stat.st_mode) && !param->d)
			ft_lslstadd_sort(&alldir, afl, param);
		else if (!(S_ISLNK(afl->stat.st_mode) && !param->l &&
					add_to_alldir(*av, &alldir, param)))
			add_to_argfl(&argfl, afl, param);
		av++;
	}
	print_errlst(errlst);
	f_a_error(argfl, param, alldir);
	return (alldir);
}
