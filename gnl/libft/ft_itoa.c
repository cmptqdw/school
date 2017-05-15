/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:36:52 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/02 15:50:52 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_firstcharitoa(char *str, int n, int neg)
{
	if (neg == -1)
		*str = '-';
	else
		*str = n + '0';
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		t;
	int		neg;

	t = n;
	i = 1;
	neg = 1;
	if (n < 0)
	{
		i++;
		neg = -1;
	}
	while ((t = t / 10))
		i++;
	if (!(str = ft_strnew(i--)))
		return (NULL);
	while (i > 0)
	{
		str[i--] = neg * (n % 10) + '0';
		n = n / 10;
	}
	ft_firstcharitoa(str, n, neg);
	return (str);
}
