/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_histo_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:26:09 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/27 16:31:03 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_histo_up(t_cmd_line *cl)
{
	t_histo *temp;

	temp = cl->histo;
	if (cl->histo && cl->histo->prev)
		cl->histo = cl->histo->prev;
	if (!cl->search)
	{
		cl->histo = cl->histo_list;
		if (!(cl->search = cmd_line_to_str(cl, cl->index)))
			return ;
	}
	if (!*cl->search && cl->histo)
		return (cmd_line_set_text(cl, cl->histo->value));
	while (cl->histo)
	{
		if (!ft_strncmp(cl->histo->value, cl->search, ft_strlen(cl->search)))
			return (cmd_line_set_text(cl, cl->histo->value));
		cl->histo = cl->histo->prev;
	}
	cl->histo = temp;
}
