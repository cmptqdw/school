/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:40:07 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 17:41:05 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_hash	*get_bins(void)
{
	static t_shell *sh = NULL;

	if (!sh)
		sh = get_shell();
	return (sh->bins);
}
