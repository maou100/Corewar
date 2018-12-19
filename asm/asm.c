/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 01:42:35 by feedme            #+#    #+#             */
/*   Updated: 2018/12/17 16:00:07 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*get_code(int fd, t_asm *data)
{
	char	*seg;

	if (!seg = ft_strnew(0))
		ft_exit_msg("malloc failed\n");
	return (seg);
}
// pr checker plusieurs instructions faire strstr 1 permiere fois puis return error si la 2eme fois marche
void	write_line(int fd, t_asm *data)
{
	char	*instr;

	if (!(instr = get_instruction(data))
		
}

int		get_instruction(t_asm *data)
{
	char	*tmp;
	int		i;
	int		instr;
	i = -1;
	instr = -1;
	tmp = NULL;
	while (++i < 17)
	{
		if (tmp = ft_strstr(data->line, g_tab[i]->name))
		{
			instr = i + 1;
			break ;
		}
	}
	if (instr != -1)
	{
		while (ft_isalpha(*tmp))
			tmp += 1;
		i = -1;
		while (++i < 17)
		{
			if (ft_strstr(tmp, g_tab[i]->name))
			{
				ft_strdel(&(data->line));
				ft_exit_msg("A non-empty line must contain valid code and only 1 instruction\n");
			}
		}
	}
	return (instr);
}

int		check_line(t_asm *data)
{
	char	*i;
	int		j;
	char	*instr;

	instr = NULL;
	if (ft_isempty(data->line))
		return (0);
	if ((data->instr = get_instruction(data)) == -1 && !get_label(data))
	{
		ft_strdel(&(data->line));
		ft_exit_msg("A non-empty line must contain valid code and only 1 instruction\n");
	}
	return (1);
}

void	assembly(int s_fd, int cor_fd)
{
	int		gnl;
	t_asm	data;

	data_init(&data);
	write_header(&data, s_fd);
	while (gnl = get_next_line(s_fd, &(data->line)))
	{
		if (gnl == -1)
			ft_exit_msg("GNL failed\n");
		if (!(check_line(data->line)))
		{
			ft_strdel(&(data->line));
			continue ;
		}
		write_line(s_fd, &data);
		ft_strdel(&(data->line));
	}
	ft_putstr_fd(data->outp, cor_fd);
}
