/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:37:57 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/30 20:35:05 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_dirstart(t_param *param)
{
	if (param->fullsb >= 0 && param->fullsb < 2000000000)
	{
		write(1, "total ", 6);
		ft_putnbr(param->fullsb);
		write(1, "\n", 1);
	}
}

void	p_usr_grp(t_lslst *allfl, t_param *param)
{
	write(1, " ", 1);
	if (!param->g)
	{
		if (allfl->spwd)
		{
			ft_putstr(allfl->spwd->pw_name);
			p_align_int_r(USRMAX + 2, allfl->usrlen);
		}
		else
		{
			ft_putnbr(allfl->stat.st_uid);
			p_align_int_r(USRMAX + 2, ft_smax(allfl->stat.st_uid));
		}
	}
	if (allfl->grp && !param->o)
	{
		ft_putstr(allfl->grp->gr_name);
		p_align_int_r(GRPMAX + 2, allfl->grplen);
	}
	else if (!param->o)
	{
		ft_putnbr(allfl->stat.st_gid);
		p_align_int_r(GRPMAX + 2, ft_smax(allfl->stat.st_gid));
	}
}

void	p_xattr(t_lslst *allfl, char *path)
{
	int		siz;
	char	*tmp;
	char	*xnam;

	(xnam = ft_strnew(84)) ? 0 : ls_malloc_error();
	if (path)
	{
		tmp = ft_strjoinkf(path, ft_strjoin("/", allfl->name));
		!tmp ? ls_malloc_error() : 0;
		siz = listxattr(tmp, xnam, 83, XATTR_NOFOLLOW);
		free(tmp);
	}
	else
		siz = listxattr(allfl->name, xnam, 83, XATTR_NOFOLLOW);
	if (siz && xnam && *xnam)
		write(1, "@ ", 2);
	else
		write(1, "  ", 2);
	free(xnam);
}

void	print_file(t_lslst *allfl, char *path, t_param *param)
{
	int		siz;

	if ((!param->au || !ft_isroot(allfl)) && param->fullsb >= 0 &&
			param->fullsb < 2000000000)
	{
		param->s ? p_s_blocks(allfl, param) : 0;
		print_fltrights(allfl);
		p_xattr(allfl, path);
		siz = ft_smax(allfl->stat.st_nlink);
		p_align_int_r(LMAX, siz);
		ft_putnbr(allfl->stat.st_nlink);
		p_usr_grp(allfl, param);
		p_device(allfl, param);
		write(1, " ", 1);
		if (param->u)
			print_time_u(allfl, param);
		else if (param->c)
			print_time_c(allfl, param);
		else
			param->uu ? print_time_uu(allfl, param) : print_time(allfl, param);
		ft_putstr(allfl->name);
		S_ISLNK(allfl->stat.st_mode) ? p_linked(allfl, path) : 0;
		write(1, "\n", 1);
	}
}

void	print_dir(t_lslst *allfl, char *path, t_param *param)
{
	allfl ? p_dirstart(param) : 0;
	while (allfl)
	{
		print_file(allfl, path, param);
		allfl = allfl->next;
	}
}
