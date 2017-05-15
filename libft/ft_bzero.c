/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:27:37 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/28 21:40:34 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char*)s;
	while (n-- > 0)
	{
		*ps = (unsigned char)'\0';
		ps++;
	}
	return (s);
}
