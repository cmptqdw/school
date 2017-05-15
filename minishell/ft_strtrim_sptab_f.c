/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:22:38 by bdesbos           #+#    #+#             */
/*   Updated: 2016/10/30 23:44:17 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strtrim_sptab_f(char *s)
{
	char	*out;
	int		d;
	int		f;

	d = 0;
	f = ft_strlen(s);
	f--;
	while (ft_isspace(s[d]))
		d++;
	if (!s[d])
	{
		free(s);
		return (NULL);
	}
	while (ft_isspace(s[f]))
		f--;
	if (!(out = ft_strsub(s, (unsigned int)d, (size_t)(f - d + 1))))
		error(0);
	free(s);
	return (out);
}
