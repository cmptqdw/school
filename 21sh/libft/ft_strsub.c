/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:31 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/04 12:55:46 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (!s[start + i])
		{
			free(str);
			return (NULL);
		}
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
