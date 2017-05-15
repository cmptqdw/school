/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:30 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/01 16:33:44 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t len;

	len = ft_strlen(src) + 1;
	if (!dst || !src)
		return (NULL);
	return (ft_memcpy(dst, src, len));
}
