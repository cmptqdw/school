/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:28 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 23:16:57 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pushchar(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	s[i++] = c;
	if (s[i])
		s[i] = 0;
	return (s);
}
