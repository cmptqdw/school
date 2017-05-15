/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_awesome.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:23:07 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/15 09:36:46 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_trianglv(t_lstp *c, t_inf *inf)
{
	double	i;
	double	a;
	double	yn;
	t_lstp	*d;
	int		k;

	d = c->next;
	while (c->x != d->x)
		d = d->next;
	fdf_calc_h(c, d, inf);
	a = (inf->x2 == inf->x1 ? 1 : (double)(inf->y2 - inf->y1) /
			(inf->x2 - inf->x1));
	i = 0;
	while ((inf->x1 + i) <= inf->x2)
	{
		yn = (inf->y1 + (double)(a * i));
		mlx_pixel_put(inf->mlx, inf->win, inf->x1 + i, yn, fdf_color(c, d));
		k = 0;
		while ((a < 0 ? yn - k : yn + k) < inf->y2)
			mlx_pixel_put(inf->mlx, inf->win, inf->x1 + i, yn + k++,
					fdf_color(c, d));
		i++;
	}
}
