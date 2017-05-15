/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:59:39 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/30 21:14:49 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_malloc_error(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	ls_error(char *name)
{
	ft_putendlf_fd(ft_strjoinkf("ls: ", ft_strjoinkf(name,
					ft_strjoin(": ", strerror(errno)))), 2);
}
