/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:44:22 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/03 19:01:37 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_exec(char *path, char **arg, int o)
{
	pid_t	dad;
	char	**xenv;

	dad = fork();
	if (dad > 0)
		wait(0);
	if (dad == -1)
		ft_putendl_fd("msh: error: program executed with a guillotine", 2);
	if (dad == 0)
	{
		if (o == 0)
			xenv = msh_tablify_env();
		else if (o == 1)
		{
			(xenv = (char**)malloc(sizeof(char*) * 1)) ? 0 : error(0);
			xenv[0] = NULL;
		}
		execve(path, arg, xenv) ?
			ft_putendl_fd("Rly ? U can't exec that, go take a coffee",
					GINF->termfd) : 0;
		exit(0);
	}
}
