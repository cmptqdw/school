/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:00:26 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/15 09:28:29 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void	cleanall(t_inf *inf, t_lstp *coo)
{
	coo ? lstpfree(coo) : 0;
	inf ? free(inf) : 0;
}

void	pre_size(t_inf *inf)
{
	inf->zoomx = (double)(LOMAX / inf->x / 3 * inf->zx);
	if (inf->x > 100)
		inf->zoomy = inf->zoomx / 1 * inf->zy;
	else if (fabs(inf->z - inf->mz) < 25)
		inf->zoomy = inf->zoomx / 10 * inf->zy;
	else
		inf->zoomy = inf->zoomx / 100 * inf->zy;
	inf->zoomz = inf->zoomx / 2.5 * inf->zz;
	inf->originx = LOMAX / 8 + inf->xx;
	inf->originy = LAMAX / 2 + inf->yy;
}

t_inf	*initinf(t_inf *inf)
{
	inf->x = 0;
	inf->y = 0;
	inf->z = 0;
	inf->lx = 0;
	inf->mx = 0;
	inf->my = 0;
	inf->mz = 0;
	inf->xx = 1;
	inf->yy = 1;
	inf->zz = 1;
	inf->zy = 1;
	inf->zx = 1;
	inf->bb = 0;
	return (inf);
}

void	fdf_launch(t_inf *inf, t_lstp *coo)
{
	pre_size(inf);
	fdf_draw(coo, inf);
	mlx_hook(inf->win, 2, 3, fdf_funkey, inf);
	mlx_loop(inf->mlx);
	cleanall(inf, coo);
}

int		main(int ac, char **av)
{
	t_inf	*inf;

	(ac != 2) ? fdf_error(0) : 0;
	(inf = (t_inf*)malloc(sizeof(t_inf))) ? 0 : fdf_error(1);
	initinf(inf);
	inf->coo = fdf_parse(fdf_read(av[1]), inf);
	inf->mlx = mlx_init();
	inf->win = mlx_new_window(inf->mlx, LOMAX, LAMAX, "my_fdf");
	fdf_launch(inf, inf->coo);
	mlx_destroy_window(inf->mlx, inf->win);
	return (1);
}
