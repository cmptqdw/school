/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:07:42 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/26 18:51:43 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*loc;
	int		i;

	i = 0;
	loc = NULL;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c || (char)c == '\0')
		loc = (char*)(&s[i]);
	return (loc);
}
