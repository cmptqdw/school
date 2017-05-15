/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifblocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 11:44:30 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 17:51:56 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verifdiese(char *fl, int i, int li, int d)
{
	if (i - 1 >= d && fl[i - 1] == '#')
		li++;
	if (i - 5 >= d && fl[i - 5] == '#')
		li++;
	if (i + 1 < d + 19 && fl[i + 1] == '#')
		li++;
	if (i + 5 < d + 19 && fl[i + 5] == '#')
		li++;
	return (li);
}

int		ft_verifblocs(char *fl)
{
	int	i;
	int	d;
	int	li;

	i = 0;
	while (fl[i])
	{
		d = i;
		li = 0;
		while (i < d + 19)
		{
			if (fl[i] == '#')
				li = ft_verifdiese(fl, i, li, d);
			i++;
		}
		if (li < 6)
			ft_error();
		i = i + 2;
	}
	li = (i + 1) / 21;
	return ((i + 1) / 21);
}
