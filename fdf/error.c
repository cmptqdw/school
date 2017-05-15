/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:22:09 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/15 06:30:54 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(int n)
{
	if (n == 0)
		ft_putendl("One and only one file in param");
	if (n == 1)
		strerror(errno);
	if (n == 2)
		ft_putendl("Empty file");
	if (n == 3)
		ft_putendl("Wrong file");
	if (n == 4)
		ft_putendl("You shall not path !");
	exit(1);
}
