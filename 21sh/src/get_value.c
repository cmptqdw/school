/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:42:08 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/14 17:42:19 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_value(char *key)
{
	static t_shell	*sh = NULL;
	char			*value;

	if (!sh)
		sh = get_shell();
	if ((value = h_get_value_by_key(sh->vars, key)))
		return (value);
	if ((value = h_get_value_by_key(sh->env, key)))
		return (value);
	return (NULL);
}
