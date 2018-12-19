/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:44:46 by feedme            #+#    #+#             */
/*   Updated: 2018/12/18 15:46:28 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

//savoir si il faut faire un check avant et s'occuper des carry aussi

void	live()

void	load(t_player *pl, unsigned char *arena)
{
	char	*tmp;
	int		reg_i;
	char	*code;
	int		ind;

	tmp = NULL;
	code = char_to_bit(arena[pl->i + 1]);
	if (code[1] == '0')
		tmp = get_dir(pl->i + 2, arena);
	else
	{
		ind = get_ind(pl->i + 2, arena);
		tmp = ft_strsub(arena, pl->i + (ind % IDX_MOD), REG_SIZE);
	}
	reg_i = (code[1] == '0') ? get_regis(pl->i + 2 + DIR_SIZE, arena) - 1 : get_regis(pl->i + 2 + IND_SIZE, arena) - 1;
	pl->regs[reg_i] = ft_memcpy(pl->regs[reg_i], tmp, REG_SIZE);
	free(tmp);
	free(code);
}

void	store(t_player *pl, unsigned char *arena)
{
	int		reg_i;
	int		i2;
	char	*code;
	int		count;

	reg_i = get_regis(pl->i + 2, arena) - 1;
	code = char_to_bit(arena[pl->i + 1]);
	if (code[2] == '0')
	{
		i2 = get_regis(pl->i + 3, arena) - 1;
		pl->regs[i2] = ft_memcpy(pl->regs[i2], pl->regs[reg_i], REG_SIZE);
	}
	else
	{
		count = -1;
		i2 = pl->i + (get_ind(pl->i + 3, arena) % IDX_MOD);
		while (++count < REG_SIZE)
			arena[i2 + count] = pl->regs[reg_i][count];
	}
	free(code);
}

void	add(t_player *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_int(pl->regs[get_regis(pl->i + 2, arena) - 1]);
	nb2 = get_int(pl->regs[get_regis(pl->i + 3, arena) - 1]);
	res = (nb1 + nb2) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->regs[get_regis(pl->i + 4, arena) - 1], tmp);
}

void	sub(t_player *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_int(pl->regs[get_regis(pl->i + 2, arena) - 1]);
	nb2 = get_int(pl->regs[get_regis(pl->i + 3, arena) - 1]);
	res = (nb1 - nb2) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->regs[get_regis(pl->i + 4, arena) - 1], tmp);
}

int		get_arg3_pos(unsigned char code)
{
	if (code & 240 == 80)
		return (4);
	else if (code & 240 == 96 || code & 240 == 144)
		return (7);
	else if (code & 240 == 112 || code & 240 == 208)
		return (5);
	else if (code & 240 == 160)
		return (10);
	else if (code & 240 == 176 || code & 240 == 224)
		return (8);
	else if (code & 240 == 240)
		return (6);
}

int		get_nb(int i, unsigned char *arena, unsigned char code, t_player *pl)
{
	if (code == 64 || code == 16)
	{

	}
	else if (code == 128 || code == 32)
	{

	}
	else
	{

	}
}

int		get_arg2_pos(unsigned char code)
{
	if (code & 192 == 64)
		return (3);
	else if (code & 192 == 128)
		return (6);
	else if (code & 192 == 192)
		return (4);
}

void	and(t_player *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_nb(pl->i + 1, arena, arena[pl->i + 1] & 192, pl);
	nb2 = get_nb(pl->i + get_arg2_pos(arena[pl->i + 1]), arena, arena[pl->i + 1] & 48, pl);
	res = (nb1 & nb2 ) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->regs[get_regis(pl->i + get_arg3_pos(arena[pl->i + 1])) - 1], tmp);


	
	if (arena[pl->i + 1] & 192 == 192)
	{
		if (arena[pl->i + 1] & 192 == 192)
		{

		}
		else
		{

		}
	}
	else
	{
		if (arena[pl->i + 1] & 192 == 192)
		{

		}
		else
		{
			
		}
	}
}
