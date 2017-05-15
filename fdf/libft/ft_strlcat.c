/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:41:12 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/10 18:46:11 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		y;
	size_t	len;

	i = ft_strlen(dst);
	len = i;
	y = 0;
	if (len >= size)
		return (size + ft_strlen(src));
	while (src[y] && i < size - 1)
		dst[i++] = src[y++];
	dst[i] = '\0';
	return (ft_strlen(src) + len);
}
