/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:31 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 23:16:59 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (!src[i])
		{
			ft_memset(dst + i, '\0', n - 1);
			return (dst);
		}
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
