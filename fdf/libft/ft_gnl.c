/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:45:29 by bdesbos           #+#    #+#             */
/*   Updated: 2016/11/02 20:34:04 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_buf(int const fd, int ret, char **save)
{
	char	*buf;

	if (!(buf = (char*)malloc(sizeof(char) * GNL_BUFF_SIZE + 1)))
		return (-1);
	if ((ret = read(fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*save = ft_strjoinf(*save, buf)))
			return (-1);
	}
	free(buf);
	return (ret);
}

int		ft_endofbuf(char **line, char **s, int fd)
{
	if (s[fd][0])
	{
		if (!(*line = ft_strdup(s[fd])))
			return (-1);
		ft_strdel(&s[fd]);
		return (1);
	}
	ft_strdel(&s[fd]);
	return (0);
}

int		gnl(int const fd, char **line)
{
	static char	*s[256];
	int			ret;
	char		*tmp;

	if (fd < 0 || fd > 255 || line == NULL
			|| (!s[fd] && (!(s[fd] = ft_strnew(0)))))
		return (-1);
	ret = 1;
	while ((!(tmp = ft_strchr(s[fd], '\n')) && ret > 0))
		if ((ret = get_next_buf(fd, ret, s + fd)) == -1)
			return (-1);
	if (ret == 0 && !tmp)
		return (ft_endofbuf(line, s, fd));
	if (!(*line = ft_strsub(s[fd], 0, tmp - s[fd])))
		return (-1);
	if (!(s[fd] = ft_strsubf(s[fd], tmp - s[fd] + 1, ft_strlen(tmp + 1))))
		return (-1);
	return (1);
}
