/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:51:07 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/02 23:20:14 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(int num)
{
	if (num == 0)
	{
		ft_putendl_fd("error: all your bash are belong to us", 2);
		exit(1);
	}
	else if (num == 2)
		exit(0);
}

void	error_quote(char *pr)
{
	ft_strdel(&pr);
	ft_putendl_fd("error: quote of the day: good quote is closed quote", 2);
}

void	error_multi(char *s)
{
	ft_strdel(&s);
	ft_putendl_fd("msh: parse error near ';;'", 2);
}
