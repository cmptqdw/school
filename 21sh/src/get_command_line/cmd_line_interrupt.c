/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_interrupt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 00:19:56 by bdesbos           #+#    #+#             */
/*   Updated: 2017/02/17 16:13:52 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "get_command_line.h"

void	cmd_line_interrupt(t_cmd_line *cl)
{
	if (get_shell()->aeof)
		return ;
	if (!cl->len)
	{
		cl->eof = 1;
		return ;
	}
	if (!cl->cursor->c)
		return ;
	cmd_line_mv_right(cl);
	cmd_line_erase(cl);
}
