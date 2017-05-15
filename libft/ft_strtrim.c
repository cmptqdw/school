/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:22:38 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/01 23:19:06 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*out;
	int		d;
	int		f;

	d = 0;
	if ((out = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		while (s[d] == ' ' || s[d] == '\n' || s[d] == '\t')
			d++;
		if (!s[d])
			return ("\0");
		f = ft_strlen(s) - 1;
		while (s[f] == ' ' || s[f] == '\n' || s[f] == '\t')
			f--;
		if ((out = ft_strsub(s, (unsigned int)d, (size_t)(f - d + 1))))
			return (out);
	}
	return (NULL);
}
