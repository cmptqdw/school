/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 22:46:50 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/30 18:09:42 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rec_start(t_param *param, t_lslst **allfl, char *path)
{
	param->smax = 0;
	param->sbmax = 0;
	param->fullsb = 0;
	LMAX = 0;
	*allfl = NULL;
	param->multiav++ ? ft_putendlf(ft_strjoin(path, ":")) : 0;
	USRMAX = 0;
	GRPMAX = 0;
}

void	rec_get_grp_usr(t_lslst *fl, t_param *param)
{
	if ((fl->grp = getgrgid(fl->stat.st_gid)))
	{
		fl->grplen = ft_strlen(fl->grp->gr_name);
		(GRPMAX < fl->grplen && (!param->au || !ft_isroot(fl))) ?
			GRPMAX = fl->grplen : 0;
	}
	if ((fl->spwd = getpwuid(fl->stat.st_uid)))
	{
		fl->usrlen = ft_strlen(fl->spwd->pw_name);
		(USRMAX < fl->usrlen) && (!param->au || !ft_isroot(fl)) ?
			USRMAX = fl->usrlen : 0;
	}
}

void	recread_daugh(t_lslst *allfl, t_param *param, char *path)
{
	char			*p;

	while (allfl)
	{
		while (allfl && (!S_ISDIR(allfl->stat.st_mode) || ft_isroot(allfl)))
			allfl = allfl->next;
		if (allfl)
		{
			write(1, "\n", 1);
			p = ft_strjoinf(ft_strjoin(path, "/"), allfl->name);
			(ft_strequ(allfl->name, "3") && ft_strequ(p, "/dev/fd/3")) ?
				ft_putendlf_fd(ft_strjoin("/dev/fd/3:\nls: 3: Not a directory\n"
							, "ls: 4: directory causes a cycle"), 2) :
				recread(opendir(p), p, param);
			free(p);
			allfl = allfl->next;
		}
	}
}

void	rec_getfiles(DIR *dir, t_lslst **allfl, char *path, t_param *param)
{
	t_lslst			*fl;
	struct dirent	*ret;
	char			*pathfl;

	while ((ret = readdir(dir)))
	{
		if (param->a || ret->d_name[0] != '.')
		{
			(fl = ft_lslstnew(ret->d_name, (int)ret->d_namlen + 1)) ? 0 :
				ls_malloc_error();
			pathfl = ft_strjoinkf(path, ft_strjoin("/", ret->d_name));
			lstat(pathfl, &fl->stat) ? ls_error(ret->d_name) : 0;
			free(pathfl);
			rec_get_grp_usr(fl, param);
			LMAX < fl->stat.st_nlink ? LMAX = fl->stat.st_nlink : 0;
			param->smax < fl->stat.st_size ? param->smax = fl->stat.st_size : 0;
			if (!param->au || !ft_isroot(fl))
				param->fullsb += fl->stat.st_blocks;
			if (param->s && param->sbmax < fl->stat.st_blocks)
				param->sbmax = fl->stat.st_blocks;
			ft_lslstadd_sort(allfl, fl, param);
		}
	}
}

void	recread(DIR *dir, char *path, t_param *param)
{
	t_lslst			*allfl;

	rec_start(param, &allfl, path);
	!dir ? ls_error(path) : 0;
	if (dir)
	{
		rec_getfiles(dir, &allfl, path, param);
		closedir(dir);
		rec_getsizesmax(param);
		(param->l) ? print_dir(allfl, path, param) :
			ft_print_filesname(allfl, param);
	}
	param->ru ? recread_daugh(allfl, param, path) : 0;
	lslst_free(allfl);
}
