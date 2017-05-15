/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veriffile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:22:35 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 16:02:46 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_veriffile(char *fl, int i)
{
	int		nb;
	int		x;
	int		y;

	y = 0;
	nb = 0;
	while (fl[i] && y != 4)
	{
		x = 0;
		while (fl[i] && x != 4)
		{
			if (fl[i] != '#' && fl[i] != '.')
				ft_error();
			if (fl[i++] == '#')
				nb++;
			x++;
		}
		if (fl[i++] != '\n')
			ft_error();
		y++;
	}
	if ((fl[i] && fl[i] != '\n') || nb != 4)
		ft_error();
	if (fl[i++])
		ft_veriffile(fl, i);
}
