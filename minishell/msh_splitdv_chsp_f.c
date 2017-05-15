/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:08:24 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/03 01:05:39 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**norm_returnmallocorerror(int q, int k)
{
	char	**tab;

	if (q == 1)
		return (NULL);
	(tab = (char**)malloc(sizeof(char *) * (k + 1))) ? 0 : error(0);
	tab[k] = NULL;
	GINF->end = k;
	return (tab);
}

void		norm_init(int *i, int *k, int *q)
{
	*i = 0;
	*k = 0;
	*q = -1;
}

static char	**ft_tabwords(char *s, char c)
{
	int		i;
	int		k;
	int		v;
	int		q;

	norm_init(&i, &k, &q);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		v = 0;
		while (s[i] && (s[i] != c || q == 1))
		{
			(q == -1 && ft_isspace(s[i])) ? s[i] = ' ' : 0;
			if (s[i] == '"')
				q = -1 * q;
			else if ((q != 1 && s[i] != ' ' && !v++))
				k++;
			else if (q == 1 && !v++)
				k++;
			i++;
		}
	}
	return (norm_returnmallocorerror(q, k));
}

char		**norm_norm(int *i, int *q, char *s)
{
	char	**tab;

	*i = 0;
	*q = -1;
	if (!(tab = ft_tabwords(s, ';')))
	{
		error_quote(s);
		return (NULL);
	}
	return (tab);
}

char		**msh_splitdv_chsp_f(char *s, int j)
{
	int		i;
	char	**tab;
	int		k;
	int		q;

	if (!(tab = norm_norm(&i, &q, s)))
		return (NULL);
	while (s[i] && j < GINF->end)
	{
		k = i;
		while (s[i] && (s[i] != ';' || q == 1))
			(s[i++] == '"') ? q = -1 * q : 0;
		if (s[i] && s[i + 1] && s[i + 1] == ';')
		{
			error_multi(s);
			ft_backtabfree(tab, --j);
			return (NULL);
		}
		(s[k] && !(tab[j] = (ft_strsub(s, k, i - k)))) ? error(0) : 0;
		tab[j] = ft_strtrim_sptab_f(tab[j]);
		j++;
		i++;
	}
	s ? free(s) : 0;
	return (tab);
}
