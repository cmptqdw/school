/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_mv_home.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 22:49:38 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 19:26:50 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_mv_home(t_cmd_line *cl)
{
	while (cl->cursor->prev)
		cmd_line_mv_left(cl);
}
