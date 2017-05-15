/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:31:23 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 17:13:45 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	if (!n)
		return (NULL);
	while (n-- > 1 && *psrc != (unsigned char)c)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
	}
	*pdst = *psrc;
	if (*psrc == (unsigned char)c)
		dst = ++pdst;
	else
		dst = NULL;
	return (dst);
}
