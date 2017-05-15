/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:45:29 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/22 01:25:45 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubf(char *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;

	i = 0;
	if ((out = (char*)malloc(sizeof(char) * (len) + 1)))
	{
		while (len-- > 0)
			out[i++] = s[start++];
		out[i] = '\0';
		free(s);
		return (out);
	}
	return (NULL);
}
