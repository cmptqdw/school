/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:06:30 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/27 21:59:39 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	*shrealloc(void *old, size_t size)
{
	if (old)
		ft_memdel(&old);
	return (shalloc(size));
}

void	*shalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = ft_memalloc(size)))
		exit_shell(ERR_MALLOC, 1);
	return (ptr);
}
