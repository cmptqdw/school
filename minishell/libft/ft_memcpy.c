/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:43:23 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/26 18:35:19 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	int				i;
	unsigned char	*psrc;

	psrc = (unsigned char*)src;
	i = 0;
	pdst = (unsigned char*)dst;
	while (n-- > 0)
	{
		*pdst = (unsigned char)psrc[i++];
		pdst++;
	}
	return (dst);
}
