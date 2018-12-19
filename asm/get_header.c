/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:19:27 by feedme            #+#    #+#             */
/*   Updated: 2018/12/09 01:41:52 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_header(t_asm *data, int fd, char *line)
{
	char	*i;
	int		j;

	j = 0;
	i = ft_strchr(line, '"');
	while (i[j + 1] != '"')
		j++;
	ft_strstr(line, NAME_CMD_STRING) ? data->name = ft_strsub(i, 1, j) : data->comment = ft_strsub(i, 1, j) ;
}

int		check_header_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] < 33)
		i++;
	if (!str[i])
		return (0);
	else if (str[i] != '.' || (!ft_strstr(str, NAME_CMD_STRING) && !ft_strstr(str, COMMENT_CMD_STRING)))
		ft_exit_msg("Syntax error: .name and .comment need to be declared before the code\n");
	return (1);
}

void	store_header(t_asm *data)
{
	int		i;

	i = -1;
	while (data->name[++i] && i < PROG_NAME_LENGTH)
		data->outp[4 + i] = data->name[i];
	i = -1;
	while (data->comment[++i] && i < COMMENT_LENGTH)
		data->outp[4 + PROG_NAME_LENGTH + i] = data->comment[i];
}

void	write_header(t_asm *data, int fd)
{
	int		gnl;
	char	*line;

	while (gnl = get_next_line(fd, &line))
	{
		if (gnl == -1)
			ft_exit_msg("GNL failed\n");
		if (!(check_header_line(data->line)))
		{
			ft_strdel(&(data->line));
			continue ;
		}
		get_header(data, fd, line);
		ft_strdel(&(data->line));
		if (data->name && data->comment)
			break ;
	}
	store_header(&data);
}
