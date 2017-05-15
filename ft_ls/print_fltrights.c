/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fltrights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:57:58 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/27 09:51:42 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_device(t_lslst *allfl, t_param *param)
{
	int		siz;

	if (S_ISCHR(allfl->stat.st_mode) || S_ISBLK(allfl->stat.st_mode))
	{
		ft_putnbr((int)major(allfl->stat.st_rdev));
		write(1, ",	", 2);
		ft_putnbr((int)minor(allfl->stat.st_rdev));
	}
	else
	{
		siz = ft_smax(allfl->stat.st_size);
		while (param->smax > siz++)
			write(1, " ", 1);
		ft_putnbr(allfl->stat.st_size);
	}
}

void	p_linked(t_lslst *allfl, char *path)
{
	char	*rlbuf;
	char	*tmp;

	write(1, " -> ", 4);
	rlbuf = ft_strnew(128);
	if (path)
	{
		tmp = ft_strjoinkf(path, ft_strjoin("/", allfl->name));
		(readlink(tmp, rlbuf, 255) == -1) ? ls_error(allfl->name) : free(tmp);
	}
	else
		(readlink(allfl->name, rlbuf, 128) == -1) ? ls_error(allfl->name) : 0;
	ft_putstr(rlbuf);
	free(rlbuf);
}

void	p_s_blocks(t_lslst *allfl, t_param *param)
{
	int		siz;

	siz = ft_smax(allfl->stat.st_blocks);
	p_align_int_r(param->sbmax, siz);
	ft_putnbr(allfl->stat.st_blocks);
	write(1, " ", 1);
}

void	p_fltr_bis(t_lslst *allfl)
{
	if (allfl->stat.st_mode & S_ISGID)
		ft_putchar(allfl->stat.st_mode & S_IXGRP ? 's' : 'S');
	else
		ft_putchar(allfl->stat.st_mode & S_IXGRP ? 'x' : '-');
	allfl->stat.st_mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	allfl->stat.st_mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	if (allfl->stat.st_mode & S_ISVTX)
		ft_putchar(allfl->stat.st_mode & S_IXOTH ? 't' : 'T');
	else
		ft_putchar(allfl->stat.st_mode & S_IXOTH ? 'x' : '-');
}

void	print_fltrights(t_lslst *allfl)
{
	if (allfl->stat.st_mode)
	{
		S_ISFIFO(allfl->stat.st_mode) ? ft_putchar('p') : 0;
		S_ISCHR(allfl->stat.st_mode) ? ft_putchar('c') : 0;
		S_ISDIR(allfl->stat.st_mode) ? ft_putchar('d') : 0;
		S_ISBLK(allfl->stat.st_mode) ? ft_putchar('b') : 0;
		S_ISREG(allfl->stat.st_mode) ? ft_putchar('-') : 0;
		S_ISLNK(allfl->stat.st_mode) ? ft_putchar('l') : 0;
		S_ISSOCK(allfl->stat.st_mode) ? ft_putchar('s') : 0;
		allfl->stat.st_mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
		allfl->stat.st_mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
		if (allfl->stat.st_mode & S_ISUID)
			ft_putchar(allfl->stat.st_mode & S_IXUSR ? 's' : 'S');
		else
			ft_putchar(allfl->stat.st_mode & S_IXUSR ? 'x' : '-');
		allfl->stat.st_mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
		allfl->stat.st_mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
		p_fltr_bis(allfl);
	}
}
