/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 23:22:21 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/03 17:19:20 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <signal.h>

# define PROMPT "\e[95mmsh $> \e[39m"
# define INF t_infos
# define GINF (get_infos())

# define LM t_lstm

typedef struct			s_lstm
{
	char				*key;
	char				*value;
	struct s_lstm		*next;
}						t_lstm;

typedef struct s_infos	t_infos;
struct					s_infos
{
	LM					*myenv;
	char				**path;
	char				*pwd;
	char				*oldpwd;
	char				*shlvl;
	char				*logname;
	char				*home;
	int					termfd;
	char				*shell;
	int					end;
};

/*
**typedef struct s_env	t_env;
**{
**	LM					altenv;
**	int					i;
**	int					v;
**	int					stop;
**}
*/

void					init(char **env, char *msh);
void					error(int num);
void					error_quote(char *pr);
void					error_multi(char *s);
char					*def_shell_name(char **av);

void					hub(char **tab, int i, int o);
void					print_env(void);
void					msh_signal(void);

void					cd_msh(char **tab);
int						setenv_msh(char **tab);
int						unsetenv_msh(char *name);
void					unsetenv_loop(char **tab);
void					msh_exec(char *path, char **arg, int o);

void					exec_path_test(char **tab, int i, int o);
void					path_loop(char **tab, int i, int o);
void					normechoch(char **tab);
void					env_msh(char **tab, int i);

t_lstm					*lstmnew(char *key, char *value);
void					lstmpush(t_lstm **alst, t_lstm *elem);
void					lstmadd(LM **alst, LM *elem);
void					lstmfree(t_lstm *alst);
INF						*get_infos(void);
void					ft_backtabfree(char **tab, int j);

char					**msh_splitdv_chsp_f(char *s, int j);
char					*ft_strtrim_sptab_f(char *s);
char					**msh_split_eq(const char *s);
char					**msh_strsplit_q(char const *s, int k, int i, int j);
char					**msh_tablify_env(void);
void					checkandmajstruct(LM *elem, char *msh);
void					checkandmajwstruct(char *key, char *value);

#endif
