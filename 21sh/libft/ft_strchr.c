/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:29 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/13 16:48:27 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!c)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
