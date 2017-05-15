/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:56:33 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 18:17:01 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_defsizeminsq(int nb)
{
	int		tmc;

	tmc = ft_sqrt(nb * 4);
	if (tmc * tmc != nb * 4)
		tmc++;
	return (tmc);
}

char	**ft_make_sq(int edge)
{
	char	**ette;
	int		i;

	i = 0;
	if ((!(ette = (char **)ft_memalloc(sizeof(char *) * edge + 1))))
		ft_error();
	while (i < edge)
	{
		if ((!(ette[i] = ft_strnew_point(edge))))
			ft_error();
		i++;
	}
	ette[i] = NULL;
	return (ette);
}

void	ft_free_sq(char **sq)
{
	char **tmp;

	tmp = sq;
	while (*sq)
	{
		free(*sq);
		sq++;
	}
	free(tmp);
}

void	ft_printsquare(char **sq)
{
	int y;

	y = 0;
	while (sq[y])
	{
		ft_putstr(sq[y++]);
		ft_putchar('\n');
	}
	ft_free_sq(sq);
}
