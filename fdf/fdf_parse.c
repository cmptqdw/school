/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:19:34 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/15 06:30:10 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*fdf_read(char *f)
{
	int		ret;
	char	*s;
	int		fd;

	(s = ft_memalloc(BUFF_SIZE + 1)) ? 0 : fdf_error(1);
	if ((fd = open(f, O_RDONLY)) < 0 || fd == 2)
		fdf_error(4);
	if (!(ret = read(fd, s, BUFF_SIZE)))
		ret == -1 ? fdf_error(1) : fdf_error(2);
	close(fd);
	return (s);
}

int		fdf_getnb(char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	s[i] == '-' ? i++ : 0;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	(tmp = ft_strsub(s, 0, i)) ? 0 : fdf_error(1);
	i = ft_atoi(tmp);
	free(tmp);
	return (i);
}

void	check_max(int x, int y, int tz, t_inf *inf)
{
	if (x > inf->x)
		inf->x = x;
	if (y > inf->y)
		inf->y = y;
	if (tz > inf->z)
		inf->z = tz;
	if (x < inf->mx)
		inf->mx = x;
	if (y < inf->my)
		inf->my = y;
	if (tz < inf->mz)
		inf->mz = tz;
}

void	norm_create(char *s, t_norm *t, t_inf *inf, t_lstp *coo)
{
	t_lstp	*tmp;

	while (ft_isblank(s[t->i]))
		t->i += 1;
	if (ft_isdigit(s[t->i]) || s[t->i] == '-')
	{
		tmp = lstpnew(t->x, t->y, fdf_getnb(s + t->i));
		check_max(t->x, t->y, tmp->z, inf);
		lstppush(&coo, tmp);
		t->x += 1;
	}
	while (s[t->i] && !(ft_isblank(s[t->i]) || s[t->i] == '\n'))
		t->i += 1;
}

t_lstp	*fdf_parse(char *s, t_inf *inf)
{
	int		i;
	int		x;
	int		y;
	t_lstp	*tmp;
	t_lstp	*coo;

	coo = norm_init(&i, &x, &y);
	while (s[++i])
	{
		while (ft_isblank(s[i]))
			i++;
		if (ft_isdigit(s[i]) || s[i] == '-')
		{
			lstppush(&coo, (tmp = lstpnew(x, y, fdf_getnb(s + i))));
			check_max(x++, y, tmp->z, inf);
		}
		while (s[i] && !(ft_isblank(s[i]) || s[i] == '\n'))
			i++;
		if (s[i] == '\n')
			x = norm_end(inf, x, &y);
	}
	free(s);
	return (coo);
}
