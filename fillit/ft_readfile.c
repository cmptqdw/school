/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:56:39 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 18:38:56 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_readfile(char *file)
{
	int		fd;
	char	*fl;
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0 || fd == 1 || fd == 2)
		ft_error();
	if (!(fl = (char*)malloc(sizeof(char) * 547)))
		ft_error();
	fl[546] = '\0';
	if (!(ret = read(fd, fl, 547)) || ret == -1 || fl[546])
	{
		close(fd);
		free(fl);
		ft_error();
	}
	fl[ret] = '\0';
	close(fd);
	return (fl);
}
