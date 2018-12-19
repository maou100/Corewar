/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:46:50 by feedme            #+#    #+#             */
/*   Updated: 2018/12/18 10:14:00 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

char	*char_to_bit(unsigned char c)
{
	char	*new;
	int		i;

	if (!(new = ft_strnew(8)))
		ft_exit_msg("Malloc error \n");
	i = 8;
	while (c > 0)
	{
		new[--i] = (c % 2) ? '1' : '0';
		c /= 2;
	}
	while (--i >= 0)
		new[i] = '0';
	return (new);
}

char	*int_to_bit(int nb)
{
	char	*new;
	int		i;

	if (!(new = ft_strnew(32)))
		ft_exit_msg("Malloc error \n");
	i = 32;
	while (c > 0)
	{
		new[--i] = (c % 2) ? '1' : '0';
		c /= 2;
	}
	while (--i >= 0)
		new[i] = '0';
	return (new);
}

void	fill_regis(unsigned char *reg, char *bits)
{
	int		i;
	int		j;

	i = 24;
	j = 3;
	while (i > -1)
	{
		reg[j] = (unsigned char)bit_to_dec(bits + i, 1);
		i -= 8;
		j--;
	}
}

char	*get_dir(int i, unsigned char *arena)
{
	char	*new;

	if (!(new = strsub(arena, i, DIR_SIZE)))
		ft_exit_msg("Malloc error \n");
	return (new);
}

int		ft_powof2(int pow)
{
	int		res;

	res = 1;
	while (--pow > -1)
		res *= 2;
	return (res);
}

int		bit_to_dec(char *str, int size)
{
	int		i;
	int		res;
	int		pow;

	pow = 0;
	res = 0;
	i = 8 * size;
	while (--i >= 0)
	{
		res += (str[i] - '0') * ft_powof2(pow);
		pow++;
	}
	return (res);
}

int		get_ind(int i, unsigned char *arena)
{
	char	*str;
	int		index;
	char	*tmp;
	char	*tmp2;
	int		j;

	j = -1;
	str = ft_strnew(0);
	while (++j < IND_SIZE)
	{
		tmp = char_to_bit(arena[i + j]);
		tmp2 = strjoin(str, tmp);
		free(str);
		free(tmp);
		str = ft_strdup(tmp2);
		free(tmp2);
	}
	index = bit_to_dec(str, IND_SIZE);
	free(str);
	return (index);
}

int		get_int(char *regis)
{
	char	*str;
	int		index;
	char	*tmp;
	char	*tmp2;
	int		j;

	j = -1;
	str = ft_strnew(0);
	while (++j < 4)
	{
		tmp = char_to_bit(regis[j]); // easy mais important: changer les strjoin etc pr que ca marche avec size
		tmp2 = strjoin(str, tmp);
		free(str);
		free(tmp);
		str = ft_strdup(tmp2);
		free(tmp2);
	}
	index = bit_to_dec(str, REG_SIZE);
	free(str);
	return (index);
}

int		get_regis(int i, unsigned char *arena)
{
	return ((int)arena[i]);
}

int		validate_codingbyte(unsigned char op_code, unsigned char c_byte)
{
	if (op_code == 1 || op_code == 9 || op_code == 12 || op_code == 15)
		if (c_byte == 128)
			return (1);
	else if (op_code == 2 || op_code == 13)
		if (c_byte == 144 || c_byte == 208)
			return (1);
	else if (op_code == 3)
		if (c_byte == 80 || c_byte == 112)
			return (1);
	else if (op_code == 4 || op_code == 5)
		if (c_byte == 84)
			return (1);
	else if (op_code == 6 || op_code == 7 || op_code == 8)
		if (c_byte == 84 || c_byte == 148 || c_byte == 212 ||
		c_byte == 228 || c_byte == 164 || c_byte == 100 ||
		c_byte == 116 || c_byte == 244 || c_byte == 180)
			return (1);
	else if (op_code == 10 || op_code == 14)
		if (c_byte == 84 || c_byte == 212 || c_byte == 148 ||
		c_byte == 100 || c_byte == 164 || c_byte == 228)
			return (1);
	else if (op_code == 11)
		if (c_byte == 84 || c_byte == 88 || c_byte == 100 ||
		c_byte == 104 || c_byte == 120 || c_byte == 116)
			return (1);
	else if (op_code == 16)
		if (c_byte == 64)
			return (1);
	return (0);
}
