/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:56:33 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 18:18:48 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_bloc(int x, int y, char **ette, t_bloc *bloc)
{
	ette[y][x] = bloc->letter;
	ette[y + bloc->d2y][x + bloc->d2x] = bloc->letter;
	ette[y + bloc->d3y][x + bloc->d3x] = bloc->letter;
	ette[y + bloc->d4y][x + bloc->d4x] = bloc->letter;
}

void	ft_del_bloc(int x, int y, char **ette, t_bloc *bloc)
{
	ette[y][x] = '.';
	ette[y + bloc->d2y][x + bloc->d2x] = '.';
	ette[y + bloc->d3y][x + bloc->d3x] = '.';
	ette[y + bloc->d4y][x + bloc->d4x] = '.';
}

int		ft_check_bloc(int x, int y, char **ette, t_bloc *bloc)
{
	int	l;

	l = ft_strlen(ette[y]);
	if (ette[y][x] == '.' &&
			y + bloc->d2y >= 0 && y + bloc->d2y < l && x + bloc->d2x >= 0 &&
			x + bloc->d2x < l && ette[y + bloc->d2y][x + bloc->d2x] == '.' &&
			y + bloc->d3y >= 0 && y + bloc->d3y < l && x + bloc->d3x >= 0 &&
			x + bloc->d3x < l && ette[y + bloc->d3y][x + bloc->d3x] == '.' &&
			y + bloc->d4y >= 0 && y + bloc->d4y < l && x + bloc->d4x >= 0 &&
			x + bloc->d4x < l && ette[y + bloc->d4y][x + bloc->d4x] == '.')
		return (1);
	return (0);
}

int		ft_isok(int x, int y, t_bloc *blocs, char **sqf)
{
	if (ft_check_bloc(x, y, sqf, blocs))
	{
		ft_place_bloc(x, y, sqf, blocs);
		if ((blocs + 1)->d2x == 42 || ft_isok(0, 0, blocs + 1, sqf))
			return (1);
		ft_del_bloc(x, y, sqf, blocs);
	}
	if (sqf[y][x + 1] && (ft_isok(x + 1, y, blocs, sqf)))
		return (1);
	if (x == ft_strlen(sqf[y]) - 1 && sqf[y + 1] &&
			ft_isok(0, y + 1, blocs, sqf))
		return (1);
	return (0);
}

char	**ft_resolve(t_bloc *blocs, int nb)
{
	char	**sqf;
	int		tc;

	tc = ft_defsizeminsq(nb);
	sqf = ft_make_sq(tc);
	while (!(ft_isok(0, 0, blocs, sqf)))
	{
		ft_free_sq(sqf);
		sqf = ft_make_sq(++tc);
	}
	return (sqf);
}
