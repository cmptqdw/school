/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:41:39 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/11 19:46:04 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int i;
	int t;
	int neg;

	i = 1;
	t = n;
	neg = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		neg = -1;
	}
	while ((t = t / 10))
		i = i * 10;
	while (i)
	{
		ft_putchar_fd(n / i * neg + '0', fd);
		n = n % i;
		i = i / 10;
	}
}
