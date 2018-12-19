/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:48:54 by feedme            #+#    #+#             */
/*   Updated: 2018/06/28 12:04:45 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *src, int n)
{
	char	*dst;
	int		i;

	i = -1;
	if (!(dst = (char*)ft_memalloc(n)))
		return (NULL);
	while (++i < n)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int		ft_extra_line(char **tab, char **line, int fd)
{
	int		i;

	i = -1;
	while (tab[fd][++i])
	{
		if (tab[fd][i] == '\n')
		{
			if (!(*line = ft_strndup(tab[fd], i)))
				return (-1);
			if (!(tab[fd] = ft_strsub(tab[fd], i + 1, ft_strlen(tab[fd]) - i)))
				return (-1);
			return (1);
		}
	}
	if (!(*line = ft_strdup(tab[fd])))
		return (-1);
	if (tab[fd])
		free(tab[fd]);
	return (0);
}

char	*ft_join(char *line, char *buf)
{
	int		i;
	int		j;
	int		line_len;
	char	*str;

	j = -1;
	line_len = ft_strlen(line);
	i = 0;
	while (buf[i] != '\n')
		i++;
	if (!(str = (char *)ft_memalloc(line_len + i + 1)))
		return (NULL);
	i = -1;
	while (line[++i])
		str[i] = line[i];
	while (buf[++j] != '\n')
		str[i + j] = buf[j];
	str[i + j] = '\0';
	if (line)
		free(line);
	return (str);
}

int		ft_gnl(char **tab, int fd, char **line, char *buf)
{
	MACRO;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(tab[fd] = ft_strchr(buf, '\n')))
		{
			if (!(tmp = ft_strjoin(*line, buf)))
				return (-1);
			if (line)
				free(*line);
			if (!(*line = ft_strdup(tmp)))
				return (-1);
			free(tmp);
		}
		else
		{
			if (MACRO1 || MACRO2)
				return (-1);
			return (1);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (ret == 0 && *line[0] != '\0')
		return (1);
	else
		return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char		**tab;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				ex_ret;

	if (fd < 0 || !line || fd > 4864 || BUFF_SIZE < 1)
		return (-1);
	if (tab == NULL)
		if (!(tab = (char **)ft_memalloc(sizeof(char *) * 4864)))
			return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (tab[fd] != NULL)
		if ((ex_ret = ft_extra_line(tab, line, fd)) != 0)
			return (ex_ret);
	ret = ft_gnl(tab, fd, line, buf);
	return (ret);
}
