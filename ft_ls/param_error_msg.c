/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:02:00 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/29 18:03:36 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			param_error(char av)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(av);
	ft_putstr("\nusage: ft_ls [-");
	ft_putstr(ARGLST);
	ft_putstr("] [file ...]\n");
	exit(1);
}
