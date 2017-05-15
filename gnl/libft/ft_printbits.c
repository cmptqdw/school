/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:26:33 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/04 16:38:01 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits(unsigned char octet)
{
	int	div;

	div = 128;
	while (div != 1)
	{
		if (octet / div == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		octet = octet % div;
		div = div / 2;
	}
	if (octet == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}
