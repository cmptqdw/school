/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:38:22 by bdesbos           #+#    #+#             */
/*   Updated: 2016/12/14 19:00:35 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_exit(t_shell *sh, char **args)
{
	if (args[0] && !str_is_digit(args[0]))
	{
		ft_putendl_fd("exit code should be a digit!", 2);
		return (1);
	}
	exit_shell(NULL, (args[0]) ? ft_atoi(args[0]) : 0);
	return (0);
	(void)sh;
	(void)args;
}
