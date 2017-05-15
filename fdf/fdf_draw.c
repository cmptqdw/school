/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:53:55 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/11 20:50:00 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_color(t_lstp *c, t_lstp *d)
{
	if ((c->z > 0 || d->z > 0))
		return (COLORT);
	if (c->z < 0 || d->z < 0)
		return (COLORB);
	return (COLORM);
}

void	fdf_calc_h(t_lstp *c, t_lstp *d, t_inf *inf)
{
	inf->x1 = (double)((c->x + c->y) * ZOOM + ORIGINX);
	inf->x2 = (double)((d->x + d->y) * ZOOM + ORIGINX);
	inf->y1 = (double)(c->y * ZOOM) - (double)(c->z * ZOOMY) -
		(double)(ZOOMZ * c->x) + ORIGINY;
	inf->y2 = (double)(d->y * ZOOM) - (double)(d->z * ZOOMY) -
		(double)(ZOOMZ * d->x) + ORIGINY;
}

void	draw_line_h(t_lstp *c, t_inf *inf)
{
	double	i;
	double	a;
	double	yn;
	double	k;

	fdf_calc_h(c, c->next, inf);
	a = (inf->x2 == inf->x1 ? 0.01 : (double)(inf->y2 - inf->y1) /
			(inf->x2 - inf->x1));
	i = 0;
	while ((inf->x1 + i) <= inf->x2)
	{
		yn = (double)(inf->y1 + (double)a * i);
		k = 0;
		mlx_pixel_put(inf->mlx, inf->win, inf->x1 + i, yn,
				fdf_color(c, c->next));
		while ((a < 0 ? yn - k : yn + k) > yn + a)
			mlx_pixel_put(inf->mlx, inf->win, inf->x1 + i, yn + k++,
					fdf_color(c, c->next));
		i++;
	}
}

void	draw_line_v(t_lstp *c, t_inf *inf)
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
		while ((a < 0 ? yn - k : yn + k) < yn + a)
			mlx_pixel_put(inf->mlx, inf->win, inf->x1 + i, yn + k++,
					fdf_color(c, d));
		i++;
	}
}

void	fdf_draw(t_lstp *coo, t_inf *inf)
{
	t_lstp	*c;

	c = coo;
	while (c)
	{
		if (c->x < inf->x)
			draw_line_h(c, inf);
		if (c->y < inf->y)
			inf->bb ? fdf_draw_trianglv(c, inf) : draw_line_v(c, inf);
		c = c->next;
	}
}
