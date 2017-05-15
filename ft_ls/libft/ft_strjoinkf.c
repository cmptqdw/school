/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:45:29 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/22 06:09:54 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinkf(const char *s1, char *s2)
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
		s2 ? free(s2) : 0;
		return (out);
	}
	return (NULL);
}
