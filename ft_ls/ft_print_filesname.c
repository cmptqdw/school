/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 22:46:50 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/23 22:51:20 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_filesname(t_lslst *allfl, t_param *param)
{
	int			siz;

	if (allfl && param->s)
	{
		write(1, "total ", 6);
		ft_putnbr(param->fullsb);
		write(1, "\n", 1);
	}
	while (allfl)
	{
		if (param->s)
		{
			siz = ft_smax(allfl->stat.st_blocks);
			while (param->sbmax > siz++)
				write(1, " ", 1);
			ft_putnbr(allfl->stat.st_blocks);
			write(1, " ", 1);
		}
		ft_putstr(allfl->name);
		write(1, "\n", 1);
		allfl = allfl->next;
	}
}
