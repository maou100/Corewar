/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:10:57 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/03 15:10:58 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/asm.h"

void	ft_change_values(t_label *label, int *codes)
{
	int i;

	i = 0;
	while (label)
	{
		if (ft_strcmp(label->label, ""))
		{
			while (i < label->argc)
			{
				codes[label->tab[i] + label->offset[i]] = label->index - label->tab[i];
				i++;
			}
		}
		label = label->next;
	}
}

int		get_codes(char *buf, int *codes, int index, t_label **label)
{
	int 	i;
	int 	j;
	char	*tmp;
	int 	ret;
	int 	*tab_label;
	int 	keep;
	int 	track;
	int 	start;

	start = index;
	tab_label = (int *)malloc(sizeof(int) * 4);
	i = 0;
	while (i < 4)
		tab_label[i++] = 0;
	track = 0;
	tmp = ft_strnew(20);
	j = 0;
	i = 0;


	while(buf[i] && buf[i] <= 32)
		i++;
	if (!ft_isalpha(buf[i]))
		return (index);
	while (ft_isalpha(buf[i]))
	{
		tmp[j] = buf[i];
		i++;
		j++;
	}
	tmp[j] = '\0';


	if (i > 0 && j > 0 && ((ret = ft_check_if_command(tmp)) > 0))
		codes[index++] = op_tab[ret].op_code;


	keep = i;
	ft_bzero(tmp, ft_strlen(tmp));
	j = 0;


	while (buf[i])
	{
		while (!ft_isalnum(buf[i]) && buf[i] != DIRECT_CHAR)
			i++;
		if ((tab_label[track++] = ft_is_label(buf[i], codes[index - 1])) > 0)
			i++;
		if (buf[i++] == LABEL_CHAR)
			while (ft_isalnum(buf[i]))
				i++;
		while (ft_isalnum(buf[i]))
			i++;
	}


	if (op_tab[ret].coding_byte)
		index = get_second_byte(codes, index, tab_label);


	i = keep;
	track = 0;


	while (buf[i])
	{
		ft_bzero(tmp, ft_strlen(tmp));
		j = 0;
		while(!ft_isalnum(buf[i]) && buf[i] != DIRECT_CHAR)
			i++;
		if (ft_is_label(buf[i], -1) != 3)
			i++;
		if (buf[i] == LABEL_CHAR)
		{
			i++;
			while (ft_isalnum(buf[i]))
				tmp[j++] = buf[i++];
			tmp[j] = '\0';
			ft_add_index_to_label(start, index, tmp, label, tab_label[track]);
			ft_bzero(tmp, ft_strlen(tmp));
			j = 0;
		}
		while (ft_isalnum(buf[i]) || buf[i] == LABEL_CHAR)
			tmp[j++] = buf[i++];
		tmp[j] = '\0';
		index = ft_get_value(tmp, codes, index, tab_label[track]);
		track++;
	}


	ft_change_values(*label, codes);


	ft_strdel(&tmp);
	ft_strdel(&tmp);
	free(tab_label);


	return (index);
}

void		ft_asm(int fd, t_asm *data)
{
	int 	ret;

	data->index = 0;
	data->buf = NULL;
	data->codes = (int *)malloc(sizeof(int) * (CHAMP_MAX_SIZE + 1));
	data->label = make_new_label();
	while ((ret = get_next_line(fd, &data->buf)) > 0)
	{
		if (ft_strstr(data->buf, ".name"))
			get_name(data);
		else if (ft_strstr(data->buf, ".comment"))
			get_comment(data);
		else if (ft_strchr(data->buf, ':') && ft_isalpha(*(ft_strchr(data->buf, ':') - 1)))
			data->index = get_label(data);
		else if (ft_strcmp(data->buf, ""))
			data->index = get_codes(data->buf, data->codes, data->index, &data->label);
		ft_strdel(&data->buf);
	}
}

void    ft_exit_msg(char *str)
{
    ft_putstr_fd(str, 2);
    exit(0);
}

char    *add_dot_cor(char *path)
{
    char     	*cor;
    int        index;

    index = 0;
    while (path[index])
    	index++;
    index--;
    while (path[index] != '.')
    	index--;
    index++;
    cor = ft_strjoin(ft_strsub(path, 0, index), "cor");
    return (cor);
}

int		main(int ac, char **av)
{
	int		s_fd;
	int 	cor_fd;
	int i = 0;
	t_asm	data;

	if (ac == 2)
	{
		if ((s_fd = open(av[ac - 1], O_RDONLY)) == -1 ||
			(cor_fd = open(add_dot_cor(av[ac - 1]), O_RDWR | O_APPEND | O_CREAT, 0755)) == -1)
			ft_exit_msg("Can't open file.\n");
		ft_asm(s_fd, &data);
	}

	while (i < data.index)
	{
		ft_putchar_fd((unsigned char)data.codes[i], cor_fd);
		i++;
	}

	i = 0;
	while (i < data.index)
	{
		ft_putnbr(data.codes[i]);
		ft_putchar('\n');
		i++;
	}
	free(data.codes);
	ft_strdel(&data.name);
	ft_strdel(&data.comment);
	return (0);
}
