/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 09:11:48 by bdesbos           #+#    #+#             */
/*   Updated: 2016/10/27 21:34:56 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabfree(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_memdel((void **)&tab[i]);
	free(tab);
	tab = NULL;
}