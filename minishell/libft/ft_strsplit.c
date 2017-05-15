/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:08:24 by bdesbos           #+#    #+#             */
/*   Updated: 2016/10/31 16:14:37 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_tabwords(char const *s, char c)
{
	int		i;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			k++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (!(tab = (char**)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	tab[k] = NULL;
	return (tab);
}

static void	ft_tabstrfree(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;
	int		k;
	int		j;

	j = 0;
	i = 0;
	if (!(tab = ft_tabwords(s, c)))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		if (s[k] && !(tab[j++] = (ft_strsub(s, k, i - k))))
		{
			ft_tabstrfree(tab, --j);
			return (NULL);
		}
	}
	return (tab);
}
