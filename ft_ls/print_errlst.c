/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 22:55:27 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/26 20:13:36 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_errlst(t_list *errlst)
{
	t_list		*deblst;

	deblst = errlst;
	while (errlst)
	{
		ft_putstr("ls: ");
		ft_putstr(errlst->content);
		ft_putstr(": No such file or directory\n");
		errlst = errlst->next;
	}
	lst_free(deblst);
}
