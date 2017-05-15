/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:41:54 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/21 20:14:20 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_bloc
{
	int			d2x;
	int			d2y;
	int			d3x;
	int			d3y;
	int			d4x;
	int			d4y;
	char		letter;
}				t_bloc;

typedef struct	s_cont
{
	t_bloc		*blocs;
	int			i;
	int			k;
	int			d;
}				t_cont;

void			ft_error(void);
char			*ft_readfile(char *file);
void			ft_veriffile(char *fl, int i);
int				ft_verifblocs(char *fl);
t_bloc			*ft_stockblocs(char *fl, int n);
void			ft_printsquare(char **sq);
char			**ft_resolve(t_bloc *blocs, int nb);
int				ft_sqrt(int n);
char			*ft_strnew_point(size_t size);
int				ft_defsizeminsq(int nb);
char			**ft_make_sq(int edge);
void			ft_free_sq(char **sq);
int				ft_strlen(const char *str);
void			*ft_memalloc(size_t size);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			*ft_bzero(void *s, size_t n);

#endif
