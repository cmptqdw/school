/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:21:32 by bdesbos           #+#    #+#             */
/*   Updated: 2016/10/27 20:40:00 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_sign_int(int sign)
{
	if (sign == SIGINT)
	{
		write(GINF->termfd, "\n", 1);
		ft_putstr_fd(PROMPT, GINF->termfd);
	}
}

void	msh_sign_tstp(int sign)
{
	if (sign == SIGTSTP)
	{
		ft_putendl_fd("\nCe n'est qu'un au revoir", GINF->termfd);
		ft_putstr_fd(PROMPT, GINF->termfd);
	}
}

void	msh_sign_segv(int sign)
{
	if (sign == SIGSEGV)
	{
		ft_putstr_fd("\nmsh: insert a new coin\n", GINF->termfd);
		exit(1);
	}
}

void	msh_sign_abrt(int sign)
{
	if (sign == SIGABRT)
	{
		ft_putstr_fd("\nmsh: moussaillon, a l'abortage !\n", GINF->termfd);
		exit(1);
	}
}

void	msh_signal(void)
{
	signal(SIGINT, msh_sign_int);
	signal(SIGTSTP, msh_sign_tstp);
	signal(SIGSEGV, msh_sign_segv);
	signal(SIGABRT, msh_sign_abrt);
}
