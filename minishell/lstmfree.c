/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 21:12:02 by bdesbos           #+#    #+#             */
/*   Updated: 2016/04/16 21:13:55 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstmfree(t_lstm *alst)
{
	if (alst)
	{
		lstmfree(alst->next);
		free(alst->key);
		alst->value ? free(alst->value) : 0;
		free(alst);
	}
}
