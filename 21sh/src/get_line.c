/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:41:10 by bdesbos           #+#    #+#             */
/*   Updated: 2017/02/17 16:22:51 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

typedef int			(*t_gl_func)(t_shell *sh, char *prompt, char **line);

static int			with_termcaps(t_shell *sh, char *prompt, char **line)
{
	int ret;

	set_term_mode(TM_RAW);
	ret = get_command_line(prompt, line, sh->histo);
	set_term_mode(TM_NORMAL);
	return (ret);
}

static int			without_termcaps(t_shell *sh, char *prompt, char **line)
{
	(void)sh;
	ft_putstr(prompt);
	return (get_next_line(0, line));
}

static t_gl_func	resolve_get_line_func(void)
{
	t_gl_func		get_line;
	char			*term;

	if (!(term = get_value("TERM")))
		return (without_termcaps);
	if (tgetent(NULL, term))
	{
		set_term_mode(TM_RAW);
		get_line = with_termcaps;
	}
	else
		get_line = without_termcaps;
	free(term);
	return (get_line);
}

static void			close_scopes(char **line, t_gl_func func)
{
	char	*prompt;
	char	*to_join;
	int		ret;

	while ((prompt = quotes_cmd_opened(line)))
	{
		if (ft_strstr(prompt, "quote"))
			*line = ft_strrejoin(*line, *line, "\n");
		if ((ret = func(get_shell(), prompt, &to_join)))
		{
			if (ret == -2)
			{
				ft_memdel((void **)line);
				return ;
			}
			if (ret == -1 || !(*line = ft_strrejoin(*line, *line, to_join)))
			{
				free(prompt);
				ft_memdel((void **)line);
				exit_shell("close scopes error!", 1);
			}
		}
		free(prompt);
		free(to_join);
	}
}

int					get_line(char *prompt, char **line)
{
	static t_shell		*sh = NULL;
	static t_gl_func	func = NULL;
	int					ret;

	if (!sh)
	{
		sh = get_shell();
		func = resolve_get_line_func();
	}
	if ((ret = func(sh, prompt, line)))
	{
		if (ret == -1)
			return (-1);
		if (!ft_strstr(prompt, "heredoc"))
		{
			sh->aeof = 1;
			close_scopes(line, func);
			sh->aeof = 0;
		}
	}
	return (ret);
}
