/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 02:30:25 by feedme            #+#    #+#             */
/*   Updated: 2018/12/10 23:41:00 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	data_init(t_asm *data)
{
	data->i_g = 0;
	data->name = NULL;
	data->comment = NULL;
	data->line = NULL;
	if (!(data->outp = ft_strnew(PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE + 15))) // 15 is 16 - 1
		ft_exit_msg("malloc failed \n");
	data->outp[0] = 0;
	data->outp[1] = 234;
	data->outp[2] = 131;
	data->outp[3] = 243;
	data->labs = NULL;
	data->instr = 0;
}

char	*get_instruction(t_asm *data)
{
	int		i;
	char	booly;
	char	*inst;

	i = -1;
	booly = 0;
	while (++i < 16)
	{
		if (inst = ft_strstr(data->line, g_tab[i]->name))
			return (g_tab[i]->name);
	}
	return (NULL);
}
