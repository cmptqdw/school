/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:19:49 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 20:34:53 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew_point(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if ((s = (char*)malloc(sizeof(char) * size + 1)))
	{
		while (i != size)
			s[i++] = '.';
		s[i] = '\0';
		return (s);
	}
	return (NULL);
}
