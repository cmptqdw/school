/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:59:37 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 19:58:16 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;

	i = 0;
	if ((out = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (len-- > 0)
			out[i++] = s[start++];
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
