/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:57:17 by amagnan           #+#    #+#             */
/*   Updated: 2018/11/12 11:56:03 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_first_part(char **line, char *str)
{
	int				i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break ;
	*line = ft_strsub(str, 0, (size_t)i);
	return (i);
}

static char			*get_other_part(char *str1, int i)
{
	char			*new;
	int				j;

	j = 0;
	new = ft_strnew((int)ft_strlen(str1) - i);
	while (str1[i + j])
	{
		new[j] = str1[i + j];
		j++;
	}
	new[j] = '\0';
	ft_strdel(&str1);
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static char		*tab[4864];
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				x;
	int				y;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	(!tab[fd]) ? tab[fd] = ft_strnew(1) : 0;
	while ((x = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[x] = '\0';
		tmp = ft_strjoin(tab[fd], buf);
		free(tab[fd]);
		tab[fd] = tmp;
		if (ft_strchr(tab[fd], '\n'))
			break ;
	}
	if (x < BUFF_SIZE && !ft_strlen(tab[fd]))
		return (0);
	y = get_first_part(line, tab[fd]);
	(y < (int)ft_strlen(tab[fd])) ? tab[fd] =
	get_other_part(tab[fd], y + 1) : ft_bzero(tab[fd], ft_strlen(tab[fd]));
	return (1);
}
