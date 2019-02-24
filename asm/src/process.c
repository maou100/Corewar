/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 03:48:45 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/08 03:48:45 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/asm.h"

/*
**			Takes a buffer and returns the name of the process
*/

void		get_name(t_asm *data)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	data->name = ft_strnew((int)ft_strlen(data->buf));
	while (data->buf[i] > 32 && data->buf[i] <= 126)
		i++;
	while (data->buf[i] == ' ' || data->buf[i] == '\t')
		i++;
	while (ft_isprint(data->buf[i]))
		data->name[j++] = data->buf[i++];
	data->name[j] = '\0';
}

/*
**			Takes a buffer and returns the comment of the process
*/

void		get_comment(t_asm *data)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	data->comment = ft_strnew((int)ft_strlen(data->buf));
	while (data->buf[i] > 32 && data->buf[i] <= 126)
		i++;
	while (data->buf[i] == ' ' || data->buf[i] == '\t')
		i++;
	while (ft_isprint(data->buf[i]))
		data->comment[j++] = data->buf[i++];
	data->comment[j] = '\0';
}

