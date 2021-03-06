/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lslst_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 05:48:06 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/22 08:29:47 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lst_free(t_list *alst)
{
	if (alst)
	{
		lst_free(alst->next);
		free(alst->content);
		free(alst);
	}
}
