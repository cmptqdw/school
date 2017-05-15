/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_premier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:12:33 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/04 21:02:06 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_premier(int n)
{
	int d;

	d = 3;
	if (n < 2 || n == 4 || n == 6 || n == 8)
		return (0);
	while (n / d >= d)
	{
		if (!(n % d))
			return (0);
		d = d + 2;
	}
	return (1);
}