/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 19:00:12 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/27 07:51:24 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_time_uu(t_lslst *allfl, t_param *param)
{
	char	*lsectime;
	char	*lstime;
	char	**word;
	char	*tmp;

	lsectime = ctime(&allfl->stat.st_birthtimespec.tv_sec);
	word = ft_strsplit(lsectime, ' ');
	tmp = word[2][1] ? ft_strdup(word[2]) : ft_strjoin(" ", word[2]);
	lstime = ft_strjoinkf(word[1], ft_strjoinkf(" ", ft_strjoinf(tmp, " ")));
	if (param->tepoch - allfl->stat.st_birthtimespec.tv_sec < 15811200 &&
			param->tepoch - allfl->stat.st_birthtimespec.tv_sec > -1)
		lstime = ft_strjoinff(lstime, ft_strsub(word[3], 0, 5));
	else
		lstime = ft_strjoinff(lstime, ft_strjoinkf(" ", ft_strsub(word[4],
						0, ft_strlen(word[4]) - 1)));
	ft_putstr(lstime);
	free(lstime);
	ft_tabfree(word);
	ft_putchar(' ');
}

void	print_time_u(t_lslst *allfl, t_param *param)
{
	char	*lsectime;
	char	*lstime;
	char	**word;
	char	*tmp;

	lsectime = ctime(&allfl->stat.st_atimespec.tv_sec);
	word = ft_strsplit(lsectime, ' ');
	tmp = word[2][1] ? ft_strdup(word[2]) : ft_strjoin(" ", word[2]);
	lstime = ft_strjoinkf(word[1], ft_strjoinkf(" ", ft_strjoinf(tmp, " ")));
	if (param->tepoch - allfl->stat.st_atimespec.tv_sec < 15811200 &&
			param->tepoch - allfl->stat.st_atimespec.tv_sec > -1)
		lstime = ft_strjoinff(lstime, ft_strsub(word[3], 0, 5));
	else
		lstime = ft_strjoinff(lstime, ft_strjoinkf(" ", ft_strsub(word[4],
						0, ft_strlen(word[4]) - 1)));
	ft_putstr(lstime);
	free(lstime);
	ft_tabfree(word);
	ft_putchar(' ');
}

void	print_time_c(t_lslst *allfl, t_param *param)
{
	char	*lsectime;
	char	*lstime;
	char	**word;
	char	*tmp;

	lsectime = ctime(&allfl->stat.st_ctimespec.tv_sec);
	word = ft_strsplit(lsectime, ' ');
	tmp = word[2][1] ? ft_strdup(word[2]) : ft_strjoin(" ", word[2]);
	lstime = ft_strjoinkf(word[1], ft_strjoinkf(" ", ft_strjoinf(tmp, " ")));
	if (param->tepoch - allfl->stat.st_ctimespec.tv_sec < 15811200 &&
			param->tepoch - allfl->stat.st_ctimespec.tv_sec > -1)
		lstime = ft_strjoinff(lstime, ft_strsub(word[3], 0, 5));
	else
		lstime = ft_strjoinff(lstime, ft_strjoinkf(" ", ft_strsub(word[4],
						0, ft_strlen(word[4]) - 1)));
	ft_putstr(lstime);
	free(lstime);
	ft_tabfree(word);
	ft_putchar(' ');
}

void	print_time(t_lslst *allfl, t_param *param)
{
	char	*lsectime;
	char	*lstime;
	char	**word;
	char	*tmp;

	lsectime = ctime(&allfl->stat.st_mtimespec.tv_sec);
	word = ft_strsplit(lsectime, ' ');
	tmp = word[2][1] ? ft_strdup(word[2]) : ft_strjoin(" ", word[2]);
	lstime = ft_strjoinkf(word[1], ft_strjoinkf(" ", ft_strjoinf(tmp, " ")));
	if (param->tepoch - allfl->stat.st_mtimespec.tv_sec < 15811200 &&
			param->tepoch - allfl->stat.st_mtimespec.tv_sec > -1)
		lstime = ft_strjoinff(lstime, ft_strsub(word[3], 0, 5));
	else
		lstime = ft_strjoinff(lstime, ft_strjoinkf(" ", ft_strsub(word[4],
						0, ft_strlen(word[4]) - 1)));
	ft_putstr(lstime);
	free(lstime);
	ft_tabfree(word);
	ft_putchar(' ');
}
