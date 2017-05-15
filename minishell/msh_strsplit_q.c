/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:08:24 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/02 19:40:30 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_tabwords(char const *s, char c)
{
	int		i;
	int		k;
	int		q;
	char	**tab;

	i = 0;
	k = 0;
	q = -1;
	while (s[i])
	{
		while (s[i] && (s[i] == c || q == 1))
			(s[i++] == '"') ? q *= -1 : 0;
		if (s[i])
			k++;
		while (s[i] && (s[i] != c || q == 1))
			(s[i++] == '"') ? q *= -1 : 0;
	}
	if ((q == 1) || !(tab = (char**)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	tab[k] = NULL;
	return (tab);
}

static void	ft_tabstrfree(char **tab, int i, int erropt)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	if (erropt)
		error(0);
}

int			ft_search(int *i, char c, char const *s)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
	return (*i);
}

char		**msh_strsplit_q(char const *s, int k, int i, int j)
{
	char	**tab;

	(!(tab = ft_tabwords(s, ' '))) ? error(0) : 0;
	while (s[i])
	{
		k = ft_search(&i, ' ', s);
		while (s[i] && s[i] != ' ')
		{
			if (s[i++] == '"')
			{
				k++;
				while (s[i] && s[i] != '"')
					i++;
				if (!s[i++])
				{
					ft_tabstrfree(tab, j--, 0);
					return (NULL);
				}
			}
		}
		if (s[k] && !(tab[j++] = (ft_strsub(s, k, (s[i - 1] == '"') ?
							i - k - 1 : i - k))))
			ft_tabstrfree(tab, --j, 1);
	}
	return ((tab ? tab : NULL));
}
