/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:28 by bdesbos           #+#    #+#             */
/*   Updated: 2015/11/29 23:16:57 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *new;

	new = malloc(sizeof(unsigned char) * len);
	ft_memcpy(new, src, len);
	ft_memcpy(dst, new, len);
	free(new);
	return (dst);
}
