/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:59:37 by bdesbos           #+#    #+#             */
/*   Updated: 2016/10/27 21:48:35 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;

	i = 0;
	if ((out = ft_strnew(len + 1)))
	{
		while (len-- > 0)
			out[i++] = s[start++];
		return (out);
	}
	return (NULL);
}
