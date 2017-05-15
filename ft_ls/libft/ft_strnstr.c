/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:32:33 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 15:33:44 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	if (!s2[j])
		return ((char*)s1);
	while (s1[i] && n-- > 0)
	{
		if (s1[i] == s2[j])
		{
			k = i;
			while (n >= j && s1[k] && s1[k] == s2[j])
			{
				k++;
				j++;
			}
			if (!s2[j])
				return ((char*)&s1[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
