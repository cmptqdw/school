/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:01:28 by bdesbos           #+#    #+#             */
/*   Updated: 2017/01/28 14:38:59 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# define OP_AND 0
# define OP_OR 1
# include "shell.h"

typedef struct s_cmd	t_cmd;
typedef struct s_redir	t_redir;
typedef enum e_rtype	t_rtype;
typedef struct s_rdef	t_rdef;
typedef enum e_ctype	t_ctype;

enum	e_ctype
{
	AND,
	OR
};

enum	e_rtype
{
	NONE,
	HD,
	READ,
	WRITE,
	APPEND,
	R_LINK,
	W_LINK
};

struct	s_redir
{
	int		from;
	int		to;
	char	*path;
	t_rtype	rtype;
	t_redir	*next;
};

struct	s_cmd
{
	char	**args;
	pid_t	pid;
	int		done;
	int		ret;
	int		to_close[2];
	t_ctype	ctype;
	t_cmd	*children;
	t_cmd	*then;
	t_redir	*redirs;
};

struct	s_rdef
{
	char	*def;
	t_rtype	rtype;
};

/*
**  PARSE
*/

t_cmd	*cmd_build(char **strp, int with_then);
int		cmd_is_operator(char *str);
int		cmd_is_redir(char *str);
int		cmd_is_arg(char *str);
int		cmd_is_skip_char(char c);
int		cmd_add_redir(t_cmd *cmd, char **strp);
int		cmd_add_arg(t_cmd *cmd, char **strp, int alias_check);
int		cmd_parse_redir(t_redir *redir, char **strp);
char	*cmd_extract_str(char **strp);
t_cmd	*cmd_free(t_cmd **cmd);

/*
**  EXEC
*/

int		cmd_exec(t_cmd *cmd);
void	cmd_exec_single(t_cmd *cmd, char **env, int must_wait);
void	cmd_handle_status(t_cmd *cmd, int status);
void	cmd_wait_group(t_cmd *cmd);
void	cmd_set_fds(t_redir *redirs, int links);
int		cmd_get_redir_fd(t_redir *redir);
void	cmd_link_pipe(t_cmd *cmd, int p[2]);

/*
**  OTHERS
*/

t_cmd	*cmd_free(t_cmd **cmd);
void	cmd_push_redir_end(t_redir **redirp, t_redir *new);
void	cmd_push_redir_front(t_redir **redirp, t_redir *new);

#endif
