/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:30 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:59 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*start;
	size_t	i;

	start = s1;
	s1 += ft_strlen(s1);
	i = 0;
	while (*s2 && i++ < n)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (start);
}
