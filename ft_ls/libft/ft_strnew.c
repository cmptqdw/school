/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:19:49 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 20:59:44 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if ((s = (char*)malloc(sizeof(char) * (size + 1))))
	{
		while (i != size + 1)
			s[i++] = '\0';
		return (s);
	}
	return (NULL);
}
