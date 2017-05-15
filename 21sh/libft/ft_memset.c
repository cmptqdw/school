/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:28 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 23:16:57 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_dest;
	unsigned char	ch;

	i = 0;
	uc_dest = dest;
	ch = c;
	while (i < n)
		uc_dest[i++] = ch;
	return (dest);
}
