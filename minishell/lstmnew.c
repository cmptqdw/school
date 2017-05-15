/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 20:49:20 by bdesbos           #+#    #+#             */
/*   Updated: 2016/04/18 22:22:43 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lstm	*lstmnew(char *key, char *value)
{
	t_lstm	*out;

	(!(out = (t_lstm*)malloc(sizeof(t_lstm)))) ? error(0) : 0;
	out->key = NULL;
	out->value = NULL;
	out->next = NULL;
	if (!key)
		return (out);
	(out->key = ft_strdup(key)) ? 0 : error(0);
	if (value)
		(out->value = ft_strdup(value)) ? 0 : error(0);
	return (out);
}
