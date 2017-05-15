/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:25:25 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 15:32:37 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*ps;
	size_t				i;

	ps = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == (unsigned char)c)
			return (&ps[i]);
		i++;
	}
	return (NULL);
}
