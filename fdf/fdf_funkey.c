/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:01:05 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/15 09:44:32 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	norm_boun(int keycode, t_inf *inf)
{
	if (keycode == 69 || keycode == 78)
	{
		(keycode == 69 && inf->zz < 2.5) ? inf->zz *= 1.1 : 0;
		keycode == 78 ? inf->zz /= 1.1 : 0;
	}
	if (keycode == 0 || keycode == 2)
	{
		keycode == 0 ? inf->xx -= 10 : 0;
		keycode == 2 ? inf->xx += 10 : 0;
	}
	if (keycode == 1 || keycode == 13)
	{
		keycode == 1 ? inf->yy += 10 : 0;
		keycode == 13 ? inf->yy -= 10 : 0;
	}
	if (keycode == 24 || keycode == 27)
	{
		(keycode == 24 && inf->zy < 1.4) ? inf->zy *= 1.1 : 0;
		(keycode == 27 && inf->zy > 0.01) ? inf->zy /= 1.1 : 0;
	}
}

void	norm_reset(int keycode, t_inf *inf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(inf->mlx, inf->win);
		ft_putendl("\e[95mHave a good day");
		exit(0);
	}
	if (keycode == 15)
	{
		inf->zz = 1;
		inf->xx = 1;
		inf->yy = 1;
		inf->zy = 1;
		inf->zy = 1;
		inf->zx = 1;
		inf->bb = 0;
	}
	if (keycode == 11)
		inf->bb = (inf->bb ? 0 : 1);
	norm_boun(keycode, inf);
}

int		fdf_funkey(int keycode, void *param)
{
	t_inf	*inf;

	inf = (t_inf*)param;
	norm_reset(keycode, inf);
	if (keycode == 82 || keycode == 65)
	{
		(keycode == 82) ? inf->zx *= 1.1 : 0;
		(keycode == 65) ? inf->zx /= 1.1 : 0;
	}
	ft_putstr("Key event ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	mlx_clear_window(inf->mlx, inf->win);
	fdf_launch(inf, inf->coo);
	return (0);
}
