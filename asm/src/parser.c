/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 03:49:39 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/08 03:49:40 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/asm.h"

int 	ft_check_if_command(char *tmp)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(op_tab[i].command, tmp) == 0)
			return (i);
		i++;
	}
	return (0);
}

/*
**		Takes a character and look if it's a label specifier
**		Returns the number of bytes required to represent the argument
*/

int		ft_is_label(char c, int code)
{
	if (c == '%')
	{
		if (code >= 0 && op_tab[code - 1].size)
			return (2);
		return (4);
	}
	else if (c == 'r')
		return (1);
	return (3);
}

/*
**		Takes an argument (tmp), the assembly code being created
**		the index we're at in codes and the info about the label.
**		We create the assembly code from these variables and fill
**		codes, while moving the index.
**		Returns the index
*/

int		ft_get_value(char *tmp, int *codes, int index, int label)
{
	int value;
	int i;

	i = 0;
	if (!tmp || !*tmp)
		value = -1;
	else
		value = ft_atoi(tmp);
	while (--label > 0)
	{
		codes[index] = 0;
		index++;
	}
	codes[index++] = value;
	return (index);
}

/*
**		This function takes the description of the type of the arguments as
**		an argument (label), creates a binary number based on the variables,
**		and then calls a function that will create a decimal number based on the binary
**
**		Need to add:	Check if the arguments types are types that fit the description in op.c,
**						if not, return an error message.
*/

int 	get_second_byte(int *codes, int index, int *label)
{
	char *bit;
	int 	i;
	int  	j;

	i = -1;
	j = 0;
	bit = ft_strnew(8);
	while(++i < 4)
	{
		bit[j++] = (label[i] == 4 || label[i] == 2 || label[i] == 3) ? '1' : '0';
		bit[j++] = (label[i] == 3 || label[i] == 1) ? '1' : '0';
		if (label[i] == 3)
			label[i] = 2;
	}
	ft_putendl(bit);
	codes[index++] = ft_bin_to_dec(bit);
	ft_strdel(&bit);
	return (index);
}

