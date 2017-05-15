/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:37:20 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/15 11:32:47 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include "string.h"
# include "fcntl.h"
# include "errno.h"
# include "math.h"

# define LOMAX 1600
# define LAMAX 1200
# define BUFF_SIZE 20000000
# define ZOOM inf->zoomx
# define ZOOMY inf->zoomy
# define ZOOMZ inf->zoomz
# define ORIGINX inf->originx
# define ORIGINY inf->originy

# define COLORM 0x00FF00
# define COLORB 0x0000FF
# define COLORT 0xF00000

typedef	struct s_lstp	t_lstp;
struct					s_lstp
{
	double				x;
	double				y;
	double				z;
	struct s_lstp		*next;
};

typedef	struct s_norm	t_norm;
struct					s_norm
{
	double				x;
	double				y;
	int					i;
	struct s_lstp		*next;
};

typedef struct s_inf	t_inf;
struct					s_inf
{
	t_lstp				*coo;
	double				x;
	double				y;
	double				z;
	double				mx;
	double				my;
	double				mz;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				lx;
	double				zoomx;
	double				zoomy;
	double				zoomz;
	double				xx;
	double				yy;
	double				zz;
	double				zy;
	double				zx;
	double				bb;
	void				*mlx;
	void				*win;
	void				*img;
	void				*img_ptr;
	double				originx;
	double				originy;
};

void					fdf_launch(t_inf *inf, t_lstp *coo);
t_lstp					*fdf_parse(char *s, t_inf *inf);
void					fdf_draw(t_lstp *coo, t_inf *inf);
int						fdf_funkey(int keycode, void *param);
int						fdf_funmouse(int keycode, int x, int y, void *param);
void					fdf_calc_h(t_lstp *c, t_lstp *d, t_inf *inf);
char					*fdf_read(char *f);
int						fdf_color(t_lstp *c, t_lstp *d);
void					fdf_error(int n);

t_lstp					*lstpnew(int x, int y, int z);
void					lstppush(t_lstp **alst, t_lstp *elem);
void					lstpfree(t_lstp *alst);

t_lstp					*norm_init(int *i, int *x, int *y);
int						norm_end(t_inf *inf, int x, int *y);

void					fdf_draw_trianglv(t_lstp *c, t_inf *inf);
void					cleanall(t_inf *inf, t_lstp *coo);

#endif
