/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockblocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 12:25:48 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 17:56:57 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_cont	cont(t_cont c)
{
	c.i = 0;
	c.k = 0;
	return (c);
}

t_bloc	*ft_stockblocs(char *fl, int n)
{
	t_cont c;

	c = cont(c);
	(!(c.blocs = (t_bloc*)malloc(sizeof(t_bloc) * n + 1))) ? ft_error() : 0;
	while (c.k < n)
	{
		while (fl[c.i] != '#')
			c.i++;
		c.d = c.i++;
		c.blocs[c.k].letter = 'A' + c.k;
		while (fl[c.i] != '#')
			c.i++;
		c.blocs[c.k].d2x = c.i % 21 % 5 - c.d % 21 % 5;
		c.blocs[c.k].d2y = c.i++ % 21 / 5 - c.d % 21 / 5;
		while (fl[c.i] != '#')
			c.i++;
		c.blocs[c.k].d3x = c.i % 21 % 5 - c.d % 21 % 5;
		c.blocs[c.k].d3y = c.i++ % 21 / 5 - c.d % 21 / 5;
		while (fl[c.i] != '#')
			c.i++;
		c.blocs[c.k].d4x = c.i % 21 % 5 - c.d % 21 % 5;
		c.blocs[c.k++].d4y = c.i++ % 21 / 5 - c.d % 21 / 5;
	}
	c.blocs[n].d2x = 42;
	return (c.blocs);
}
