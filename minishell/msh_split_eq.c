/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split_eq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 20:58:38 by bdesbos           #+#    #+#             */
/*   Updated: 2016/10/27 21:51:41 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**msh_split_eq(const char *s)
{
	int		i;
	char	**tab;

	i = 0;
	(tab = (char**)malloc(sizeof(char*) * 3)) ? 0 : error(0);
	tab[2] = NULL;
	while (s[i] != '=')
		i++;
	(tab[0] = ft_strsub(s, 0, i++)) ? 0 : error(0);
	(tab[1] = ft_strsub(s, i, ft_strlen(s) - i)) ? 0 : error(0);
	return (tab);
}
