/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:45:29 by bdesbos           #+#    #+#             */
/*   Updated: 2016/01/22 22:54:32 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;

	i = 0;
	if ((out = (char*)malloc(sizeof(char) * (len) + 1)))
	{
		while (len-- > 0)
			out[i++] = s[start++];
		out[i] = '\0';
		free(s);
		return (out);
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*out;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((out = (char*)malloc(sizeof(char) * i)))
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			out[i] = s1[i];
			i++;
		}
		while (s2[j])
			out[i++] = s2[j++];
		out[i] = '\0';
		free(s1);
		return (out);
	}
	return (NULL);
}

int		get_next_buf(int const fd, int ret, char **save)
{
	char	*buf;

	if (!(buf = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*save = ft_strjoin_free(*save, buf)))
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

int		get_next_line(int const fd, char **line)
{
	static char	*s[256];
	int			ret;
	char		*tmp;

	if (fd < 0 || fd == 1 || fd == 2 || fd > 255 || line == NULL
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
	if (!(s[fd] = ft_strsub_free(s[fd], tmp - s[fd] + 1, ft_strlen(tmp + 1))))
		return (-1);
	return (1);
}
