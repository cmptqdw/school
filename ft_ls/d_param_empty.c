/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callparamlempty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:59:14 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/30 18:25:00 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dpe(t_param *param)
{
	char	**empty;
	t_lslst	*afl;
	t_lslst **fl;

	(afl = ft_lslstnew(".", 2)) ? 0 : ls_malloc_error();
	fl = NULL;
	empty = (char**)malloc(sizeof(char*) + 1);
	empty[0] = (char*)malloc(sizeof(char) + 1);
	empty[0][0] = '.';
	empty[0][1] = '\0';
	empty[1] = NULL;
	if (lstat(".", &afl->stat))
		ls_error(".");
	else
		files_and_errors(empty, param, 1);
}
