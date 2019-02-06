/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:44:46 by feedme            #+#    #+#             */
/*   Updated: 2019/02/06 10:24:19 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

//savoir si il faut faire un check avant et s'occuper des carry aussi

//il faut p-e faire la representation en octal pck ds aff ils disent que 52 va donner *

//si on fait des errors check (ex: reg == 50), il faudrait le faire avant de call les instrs pr pouvoir exit sans se preoccuper des free

void	live(t_player *pl, unsigned char *arena)
{
	process->life_count++;
	process->players_lives[get_ind(i, arena, DIR_SIZE)]++;
}

char	*cw_strsub(unsigned char *arena, int i, int size)
{
	char	*new;
	int		j;

	j = -1;
	if (!(new = ft_strnew(size + 1)))
		exit(-1);
	new[size] = '\0';
	while (++j < size)
		new[j] = arena[(i + j) % MEM_SIZE];
	return (new);
}

void	load(t_player *pl, unsigned char *arena)
{
	char	*tmp;
	int		reg_i;
	char	*code;
	int		ind;

	tmp = NULL;
	code = char_to_bit(arena[(pl->i + 1) % MEM_SIZE]);
	if (code[1] == '0')
		tmp = get_dir((pl->i + 2) % MEM_SIZE, arena);
	else
	{
		ind = get_ind((pl->i + 2) % MEM_SIZE, arena, IND_SIZE);
		tmp = cw_strsub(arena, (pl->i + (ind % IDX_MOD)) % MEM_SIZE, REG_SIZE);
	}
	reg_i = (code[1] == '0') ? get_regis((pl->i + 2 + DIR_SIZE) % MEM_SIZE, arena) - 1 : get_regis((pl->i + 2 + IND_SIZE) % MEM_SIZE, arena) - 1;
	pl->regs[reg_i] = ft_memcpy(pl->regs[reg_i], tmp, REG_SIZE);
	free(tmp);
	free(code);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	store(t_player *pl, unsigned char *arena)
{
	int		reg_i;
	int		i2;
	char	*code;
	int		count;

	reg_i = get_regis((pl->i + 2) % MEM_SIZE, arena) - 1;
	code = char_to_bit(arena[(pl->i + 1) % MEM_SIZE]);
	if (code[2] == '0')
	{
		i2 = get_regis((pl->i + 3) % MEM_SIZE, arena) - 1;
		pl->regs[i2] = ft_memcpy(pl->regs[i2], pl->regs[reg_i], REG_SIZE);
	}
	else
	{
		count = -1;
		i2 = pl->i + (get_ind((pl->i + 3) % MEM_SIZE, arena, IND_SIZE) % IDX_MOD);
		while (++count < REG_SIZE)
			arena[(i2 + count) % MEM_SIZE] = pl->regs[reg_i][count];
	}
	free(code);
}

void	add(t_player *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_ind(0, pl->regs[get_regis((pl->i + 2) % MEM_SIZE, arena) - 1], REG_SIZE);
	nb2 = get_ind(0, pl->regs[get_regis((pl->i + 3) % MEM_SIZE, arena) - 1], REG_SIZE);
	res = (nb1 + nb2) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->regs[get_regis((pl->i + 4) % MEM_SIZE, arena) - 1], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	sub(t_player *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_ind(0, pl->regs[get_regis((pl->i + 2) % MEM_SIZE, arena) - 1], REG_SIZE);
	nb2 = get_ind(0, pl->regs[get_regis((pl->i + 3) % MEM_SIZE, arena) - 1], REG_SIZE);
	res = (nb1 - nb2) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->regs[get_regis((pl->i + 4) % MEM_SIZE, arena) - 1], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
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
	int	index;

	if (code == 4 || code == 16 || code == 64)
		return (get_ind(0, pl->regs[get_regis(arena, i) - 1], REG_SIZE));
	else if (code == 8 || code == 32 || code == 128)
		return (get_ind(i, arena, DIR_SIZE));
	else
	{
		index = get_ind(i, arena, IND_SIZE);
		return (get_ind((pl->i + (index % IDX_MOD)) % MEM_SIZE, arena, IND_SIZE));
	}
}

int		get_lnb(int i, unsigned char *arena, unsigned char code, t_player *pl)
{
	int	index;

	if (code == 4 || code == 16 || code == 64)
		return (get_ind(0, pl->regs[get_regis(arena, i) - 1], REG_SIZE));
	else if (code == 8 || code == 32 || code == 128)
		return (get_ind(i, arena, DIR_SIZE));
	else
	{
		index = get_ind(i, arena, IND_SIZE);
		return (get_ind((pl->i + index) % MEM_SIZE, arena, IND_SIZE));
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

	nb1 = get_nb(((pl->i + 2) % MEM_SIZE), arena, arena[(pl->i + 1) % MEM_SIZE] & 192, pl);
	nb2 = get_nb((pl->i + get_arg2_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 48, pl);
	res = (nb1 & nb2 ) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->regs[get_regis((pl->i + get_arg3_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE) - 1], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	or(t_player *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_nb(((pl->i + 2) % MEM_SIZE), arena, arena[(pl->i + 1) % MEM_SIZE] & 192, pl);
	nb2 = get_nb((pl->i + get_arg2_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 48, pl);
	res = (nb1 | nb2 ) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->regs[get_regis((pl->i + get_arg3_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE) - 1], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	xor(t_player *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_nb(((pl->i + 2) % MEM_SIZE), arena, arena[(pl->i + 1) % MEM_SIZE] & 192, pl);
	nb2 = get_nb((pl->i + get_arg2_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 48, pl);
	res = (nb1 ^ nb2 ) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->regs[get_regis((pl->i + get_arg3_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE) - 1], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	zjump(t_player *pl, unsigned char *arena)
{
	int	index;

	index = get_ind((pl->i + 1) % MEM_SIZE, arena, IND_SIZE);
	if (pl->carry == 1)
	{
		pl->i += (index % IDX_MOD);
		pl->i %= MEM_SIZE;
	}
}

void	ldi(t_player *pl, unsigned char *arena)
{
	int		index;
	int		i1;
	int		i2;
	int		reg_i;
	char	*tmp;

	i1 = get_nb((pl->i + 2) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 192, pl);
	i2 = get_nb((pl->i + get_arg2_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 48, pl);
	index = (i1 + i2) % IDX_MOD;
	tmp = cw_strsub(arena, (pl->i + index) % MEM_SIZE, REG_SIZE);
	reg_i = get_regis((pl->i + get_arg3_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena) - 1;
	pl->regs[reg_i] = ft_memcpy(pl->regs[reg_i], tmp, REG_SIZE);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	sti(t_player *pl, unsigned char *arena)
{
	int		index;
	int		i1;
	int		i2;
	int		reg_i;
	int		i;

	i = -1;
	i1 = get_nb((pl->i + get_arg2_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 48, pl);
	i2 = get_nb((pl->i + get_arg3_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 12, pl);
	index = (i1 + i2) % MEM_SIZE;
	reg_i = get_regis(arena[(pl->i + 2) % MEM_SIZE]) - 1;
	while (++i < 4)
		arena[(i + pl->i + index) % MEM_SIZE] = pl->regs[reg_i][i];
}

void	fork(t_player *pl, unsigned char *arena)
{
	int		index;
	int		new_i;

	index = get_ind((pl->i + 1) % MEM_SIZE, arena, IND_SIZE);
	new_i = (pl->i + (index % IDX_MOD)) % MEM_SIZE;
	new_process(new_i, &pl, arena);
}

void	aff(t_player *pl, unsigned char *arena)
{
	char	*bits;
	int		i;
	unsigned char	c;
	int		reg;

	i = -1;
	if (!(bits = ft_strnew(4)))
		exit(-1);
	reg = (int)arena[(pl->i + 2) % MEM_SIZE];
	while (++i < 4)
		bits[i] = char_to_bit(pl->regs[reg][i]);
	c = (unsigned char)(bit_to_dec(bits, 4) % 256);
	write(1, &c, 1);
}

void	lld(t_player *pl, unsigned char *arena)
{
	char	*tmp;
	int		reg_i;
	char	*code;
	int		ind;

	tmp = NULL;
	code = char_to_bit(arena[(pl->i + 1) % MEM_SIZE]);
	if (code[1] == '0')
		tmp = get_dir((pl->i + 2) % MEM_SIZE, arena);
	else
	{
		ind = get_ind((pl->i + 2) % MEM_SIZE, arena, IND_SIZE);
		tmp = cw_strsub(arena, (pl->i + ind) % MEM_SIZE, REG_SIZE);
	}
	reg_i = (code[1] == '0') ? get_regis((pl->i + 2 + DIR_SIZE) % MEM_SIZE, arena) - 1 : get_regis((pl->i + 2 + IND_SIZE) % MEM_SIZE, arena) - 1;
	pl->regs[reg_i] = ft_memcpy(pl->regs[reg_i], tmp, REG_SIZE);
	free(tmp);
	free(code);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	lldi(t_player *pl, unsigned char *arena)
{
	int		index;
	int		i1;
	int		i2;
	int		reg_i;
	char	*tmp;

	i1 = get_lnb((pl->i + 2) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 192, pl);
	i2 = get_lnb((pl->i + get_arg2_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->i + 1) % MEM_SIZE] & 48, pl);
	index = (i1 + i2) % MEM_SIZE;
	tmp = cw_strsub(arena, (pl->i + index) % MEM_SIZE, REG_SIZE);
	reg_i = get_regis((pl->i + get_arg3_pos(arena[(pl->i + 1) % MEM_SIZE])) % MEM_SIZE, arena) - 1;
	pl->regs[reg_i] = ft_memcpy(pl->regs[reg_i], tmp, REG_SIZE);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	lfork(t_player *pl, unsigned char *arena)
{
	int		index;
	int		new_i;

	index = get_ind((pl->i + 1) % MEM_SIZE, arena, IND_SIZE);
	new_i = (pl->i + index) % MEM_SIZE;
	new_process(new_i, pl, arena);
	pl->carry = (pl->carry) ? 0 : 1;
}

