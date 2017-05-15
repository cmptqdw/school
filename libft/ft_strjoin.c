/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:10:17 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/28 22:48:20 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*out;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((out = (char*)malloc(sizeof(char) * i)))
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			out[i] = s1[i];
			i++;
		}
		while (s2[j])
			out[i++] = s2[j++];
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
