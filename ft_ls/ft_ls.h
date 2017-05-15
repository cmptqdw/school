/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:18:29 by bdesbos           #+#    #+#             */
/*   Updated: 2016/03/30 19:27:38 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <sys/attr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>

# define ARGLST "GRSUacdfglrstu1"
# define STAT struct stat
# define LSD struct s_lslst
# define LMAX param->slmax
# define USRMAX param->usrmax
# define GRPMAX param->grpmax

typedef LSD			t_lslst;

typedef	struct		s_param
{
	int				(*f_sort)(t_lslst *, t_lslst *);
	int				l;
	int				a;
	int				au;
	int				un;
	int				u;
	int				uu;
	int				r;
	int				c;
	int				t;
	int				ru;
	int				s;
	int				f;
	int				g;
	int				o;
	int				gu;
	int				d;
	int				su;
	time_t			tepoch;
	int				smax;
	int				sbmax;
	double			fullsb;
	int				slmax;
	int				multiav;
	int				usrmax;
	int				grpmax;
}					t_param;

struct				s_lslst
{
	char			*name;
	size_t			name_size;
	int				type;
	struct s_lslst	*next;
	STAT			stat;
	struct group	*grp;
	int				grplen;
	struct passwd	*spwd;
	int				usrlen;
	char			*xattr;
};

void				init_param(t_param *param);
void				check_params(char *av, t_param *param);
int					param_error(char av);
void				select_sort(t_param *param);
void				dpe(t_param *param);

t_lslst				*files_and_errors(char **av, t_param *param, int ac);
void				recread(DIR *dir, char *path, t_param *param);
void				rec_getsizesmax(t_param *param);

void				print_dir(t_lslst *allfl, char *path, t_param *param);
void				print_file(t_lslst *allfl, char *path, t_param *param);
void				print_fltrights(t_lslst *allfl);
void				p_s_blocks(t_lslst *allfl, t_param *param);
void				p_linked(t_lslst *allfl, char *path);
void				p_device(t_lslst *allfl, t_param *param);
void				print_time(t_lslst *allfl, t_param *param);
void				print_time_u(t_lslst *allfl, t_param *param);
void				print_time_uu(t_lslst *allfl, t_param *param);
void				print_time_c(t_lslst *allfl, t_param *param);
void				ft_print_filesname(t_lslst *allfl, t_param *param);
void				print_errlst(t_list *errlst);

void				p_align_int_r(int max, int siz);

void				ls_error(char *name);
void				ls_malloc_error(void);

t_lslst				*ft_lslstnew(char *name, size_t name_size);
void				ft_lstadd_sort(t_list **alst, t_list *new);
void				ft_lslstadd_sort(t_lslst **alst, t_lslst *new,
					t_param *param);
int					ft_isroot(t_lslst *fl);
int					ft_smax(int n);

int					ls_cmp(t_lslst *run, t_lslst *new);
int					ls_cmp_r(t_lslst *run, t_lslst *new);
int					ls_cmp_t(t_lslst *run, t_lslst *new);
int					ls_cmp_tr(t_lslst *run, t_lslst *new);
int					ls_cmp_tu(t_lslst *run, t_lslst *new);
int					ls_cmp_tur(t_lslst *run, t_lslst *new);
int					ls_cmp_tuu(t_lslst *run, t_lslst *new);
int					ls_cmp_tuur(t_lslst *run, t_lslst *new);
int					ls_cmp_s(t_lslst *run, t_lslst *new);
int					ls_cmp_sr(t_lslst *run, t_lslst *new);
int					ls_cmp_tc(t_lslst *run, t_lslst *new);
int					ls_cmp_tcr(t_lslst *run, t_lslst *new);

void				lslst_free(t_lslst *alst);
void				lst_free(t_list *alst);

#endif
