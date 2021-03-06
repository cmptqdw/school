/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_source_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:44:41 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/30 20:06:41 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_source_fd(t_shell *sh, int fd)
{
	int		ret;
	char	*line;

	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (exit_shell(ERR_READ, 1));
		if (*line != '#')
			shell_source_line(sh, line);
		ft_memdel((void **)&line);
	}
	if (line)
		free(line);
}
