/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:35:25 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/31 15:40:02 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void		cmd_line_render(t_cmd_line *cl)
{
	t_cl_char *temp;

	ft_putstr(cl->prompt);
	temp = cl->cursor;
	cl->cursor = cl->chars;
	cl->col = cl->pcol;
	while (cl->cursor->next)
	{
		++cl->col;
		if (cl->col > cl->cols)
			cl->col = 1;
		ft_putwchar(cl->cursor->c);
		cl->cursor = cl->cursor->next;
	}
	while (temp != cl->cursor)
		cmd_line_mv_left(cl);
}
