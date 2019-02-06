/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:46:50 by feedme            #+#    #+#             */
/*   Updated: 2019/01/05 16:16:43 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

char	*char_to_bit(unsigned char c)
{
	char	*bitstr;
	int		i;

	if (!(bitstr = ft_strnew(9)))
		ft_exit_msg("Malloc error \n");
	bitstr[8] = '\0';
	i = 8;
	while (c > 0)
	{
		bitstr[--i] = (c % 2) ? '1' : '0';
		c /= 2;
	}
	while (--i >= 0)
		bitstr[i] = '0';
	return (bitstr);
}

char	*int_to_bit(int c)
{
	char	*bitstr;
	int		i;

	if (!(bitstr = ft_strnew(33)))
		ft_exit_msg("Malloc error \n");
	bitstr[32] = '\0';
	i = 32;
	while (c > 0)
	{
		bitstr[--i] = (c % 2) ? '1' : '0';
		c /= 2;
	}
	while (--i >= 0)
		bitstr[i] = '0';
	return (bitstr);
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
	int		j;

	j = -1;
	if (!(new = ft_strnew(DIR_SIZE + 1)))
		exit(-1);
	new[DIR_SIZE] = '\0';
	while (++j < DIR_SIZE)
		new[j] = arena[(i + j) % MEM_SIZE]
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

int		get_ind(int i, unsigned char *arena, int size)
{
	char	*str;
	int		index;
	char	*tmp;
	char	*tmp2;
	int		j;

	j = -1;
	str = ft_strnew(0);
	while (++j < size)
	{
		tmp = char_to_bit(arena[(i + j) % MEM_SIZE]);
		tmp2 = strjoin(str, tmp);
		free(str);
		free(tmp);
		str = ft_strdup(tmp2);
		free(tmp2);
	}
	index = bit_to_dec(str, size);
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
