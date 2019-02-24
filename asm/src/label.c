/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 03:46:58 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/08 03:46:58 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/asm.h"

/*
**			Makes a new node of struct label
*/

t_label 	*make_new_label(void)
{
	t_label *new;
	int 	i;

	i = 0;
	new = (t_label *)malloc(sizeof(t_label));
	new->tab = (int *)malloc(sizeof(int) * 682);
	while (i < 682)
		new->tab[i++] = -1;
	new->offset = (int *)malloc(sizeof(int) * 682);
	while (i < 682)
		new->offset[i++] = -1;
	new->argc = 0;
	new->label = ft_strdup("");
	new->index = 0;
	new->found = 0;
	new->next = NULL;
	return (new);
}

/*
**		Adds the informations about where to find the definition of the label
*/

void	add_label(char *tmp, int index, t_label **label)
{
	int i;
	t_label *current;

	current = *label;
	i = 0;
	if (!current)
		current = make_new_label();
	else
	{
		while (current && current->next && ft_strcmp(current->label, tmp))
			current = current->next;
		if (!current->next && ft_strcmp(current->label, tmp))
		{
			current->next = make_new_label();
			current = current->next;
		}
	}
	current->label = ft_strdup(tmp);
	current->index = index;
	current->found = 1;
	current->next = NULL;
}

/*
**		Function called when we have the definition of the label in buf
*/

int 	get_label(t_asm *data)
{
	int i;
	char *tmp;
	int j;
	int ret;

	j = 0;
	tmp = ft_strnew(20);
	i = 0;
	while (data->buf[i] && data->buf[i] <= 32)
		i++;
	while (ft_isalnum(data->buf[i]) || data->buf[i] == LABEL_CHAR)
		tmp[j++] = data->buf[i++];
	tmp[j] = '\0';
	if ((ret = ft_check_if_command(tmp)) > 0)
		return (get_codes(data->buf, data->codes, data->index, &data->label));
	else
	{
		if (tmp[--j] == ':')
		{
			tmp[j] = '\0';
			add_label(tmp, data->index, &data->label);
			ft_bzero(tmp, ft_strlen(tmp));
		}
		j = 0;
		while (data->buf[i] && data->buf[i] <= 32)
			i++;
		while (ft_isalnum(data->buf[i]) || data->buf[i] == LABEL_CHAR)
			tmp[j++] = data->buf[i++];
		tmp[j++] = '\0';
		if ((ret = ft_check_if_command(tmp)) > 0)
			return (get_codes(data->buf + i - (int)ft_strlen(tmp), data->codes, data->index, &data->label));
	}
	return (data->index);
}

/*
**		Adds a coordinate where we have a call to a label
*/

void	ft_add_index_to_label(int index, int real_index, char *name, t_label **label, int size)
{
	t_label *current;
	int i;

	i = 0;
	current = *label;
	while (current && current->next && ft_strcmp(current->label, name))
		current = current->next;
	if (!current->next && ft_strcmp(current->label, name))
	{
		current->next = make_new_label();
		current->next->label = ft_strdup(name);
		current = current->next;
	}
	current->tab[current->argc] = index;
	current->offset[current->argc] = real_index - index + size - 1;
	current->argc++;
}
