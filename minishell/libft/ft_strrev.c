/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 07:01:40 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/31 07:32:19 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		k;

	i = 0;
	k = ft_strlen(str);
	rev = ft_memalloc(k-- + 1);
	while (str[i])
		rev[k--] = str[i++];
	return (rev);
}
