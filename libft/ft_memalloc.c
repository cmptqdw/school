/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:26:25 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/28 16:45:21 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	int		i;

	i = 0;
	if ((mem = malloc(size)))
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
