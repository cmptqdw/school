/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_mv_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:46:30 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 19:26:57 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_mv_right(t_cmd_line *cl)
{
	if (!cl->cursor->next)
		return ;
	ft_putstr(tgetstr("nd", NULL));
	++cl->col;
	++cl->index;
	if (cl->col > cl->cols)
	{
		cl->col = 1;
		ft_putstr(tgetstr("cr", NULL));
		ft_putstr(tgetstr("do", NULL));
	}
	cl->cursor = cl->cursor->next;
}
