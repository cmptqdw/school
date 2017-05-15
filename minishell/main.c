/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 23:19:51 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/03 00:38:51 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*norm_trololo(int *i)
{
	*i = -1;
	return (NULL);
}

void	callgnl(char **pr)
{
	int		ret;

	ret = (gnl(0, pr));
	if (ret < 0)
		error(0);
	else if (ret == 0 && !*pr)
		exit(0);
}

void	fire_and_forget(char *pr, char **tab, char **toson, int i)
{
	while (tab && tab[0] && tab[++i])
	{
		if ((toson = msh_strsplit_q(tab[i], 0, 0, 0)))
			hub(toson, 0, 0);
		else
			error_quote(pr);
		toson ? ft_tabfree(toson) : 0;
	}
}

int		main(int ac, char **av, char **env)
{
	char	*pr;
	char	**tab;
	char	**toson;
	int		i;

	(void)ac;
	init(env, def_shell_name(av));
	while (36)
	{
		pr = norm_trololo(&i);
		toson = NULL;
		ft_putstr_fd(PROMPT, GINF->termfd);
		callgnl(&pr);
		if (*pr)
		{
			(tab = msh_splitdv_chsp_f(pr, 0));
			tab ? fire_and_forget(pr, tab, toson, i) : 0;
			tab ? ft_tabfree(tab) : 0;
		}
		else
			free(pr);
	}
	(close((get_infos())->termfd) != -2) ? lstmfree(GINF->myenv) : 0;
	return (0);
}
