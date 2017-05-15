/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:26 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 20:41:20 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrejoin(char *orig, char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	if (orig)
		free(orig);
	return (tmp);
}
