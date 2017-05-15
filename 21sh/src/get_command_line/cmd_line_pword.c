/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_pword.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 22:55:36 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 19:27:04 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_pword(t_cmd_line *cl)
{
	if (!cl->cursor->prev)
		return ;
	cmd_line_mv_left(cl);
	if (cl->cursor->prev && cl->cursor->c != ' ' && cl->cursor->prev->c == ' ')
		return ;
	cmd_line_pword(cl);
}
