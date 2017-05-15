/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:19:34 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 23:35:40 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lstp	*norm_init(int *i, int *x, int *y)
{
	*i = -1;
	*x = 0;
	*y = 0;
	return (NULL);
}

int		norm_end(t_inf *inf, int x, int *y)
{
	!inf->lx ? inf->lx = x : 0;
	x != inf->lx ? fdf_error(3) : 0;
	*y += 1;
	return (0);
}
