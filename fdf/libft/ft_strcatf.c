/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:23:04 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/23 17:47:33 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatf(char *dst, char *src)
{
	int	i;
	int	y;

	y = 0;
	i = ft_strlen(src);
	while (src[y])
		dst[i++] = src[y++];
	dst[i] = '\0';
	free(src);
	return (dst);
}
