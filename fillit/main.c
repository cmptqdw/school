/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:45:13 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 22:55:58 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*file;
	t_bloc	*blocs;
	int		nbblocs;
	char	**square;

	if (ac != 2)
		ft_error();
	file = ft_readfile(av[1]);
	ft_veriffile(file, 0);
	nbblocs = ft_verifblocs(file);
	blocs = ft_stockblocs(file, nbblocs);
	square = ft_resolve(blocs, nbblocs);
	ft_printsquare(square);
	return (0);
}
