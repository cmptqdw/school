/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_racinecarree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:45:50 by bdesbos           #+#    #+#             */
/*   Updated: 2015/12/04 17:11:02 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_racinecarree(int n)
{
	int rac;

	rac = 0;
	while (rac * rac < n)
		rac = rac + 1;
	if (rac * rac == n)
		return (rac);
	return (0);
}
