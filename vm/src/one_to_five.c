/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_to_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:44:46 by feedme            #+#    #+#             */
/*   Updated: 2019/02/16 13:22:20 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"
#include <fcntl.h>
//savoir si il faut faire un check avant et s'occuper des carry aussi

//il faut p-e faire la representation en octal pck ds aff ils disent que 52 va donner *

//si on fait des errors check (ex: reg == 50), il faudrait le faire avant de call les instrs pr pouvoir exit sans se preoccuper des free

//il n'y a pas de negatifs dans la VM, ils doivent avoir ete convertits en positifs dans l'asm

void	set_last_alive(t_vm *vm, char *tmp)
{
	if (!ft_memcmp(vm->p1->nbr, tmp, DIR_SIZE))
	{
		vm->p1->last_live = 1;
		vm->p2->last_live = 0;
		//SET MESSAGE(A process shows that player vm->p1->nbr (vm->p1->header->prog_name) is alive);
	}
	else if (!ft_memcmp(vm->p2->nbr, tmp, DIR_SIZE))
	{
		vm->p1->last_live = 0;
		vm->p2->last_live = 1;
		//SET MESSAGE(A process shows that player vm->p2->nbr (vm->p2->header->prog_name) is alive);
	}
}

void	live(t_process *pl, unsigned char *arena, t_vm *vm)
{
	char	*tmp;
	vm->nlive++;
	pl->nlive++;
	tmp = get_dir(pl->index + 1, arena);
	if (!ft_memcmp(pl->r[0], tmp, DIR_SIZE))
		set_last_alive(vm, tmp);
	free(tmp);
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

void	load(t_process *pl, unsigned char *arena)
{
	char	*tmp;
	int		reg_i;
	char	*code;
	int		ind;

	tmp = NULL;
	code = char_to_bit(arena[(pl->index + 1) % MEM_SIZE]);
	if (code[1] == '0')
		tmp = get_dir((pl->index + 2) % MEM_SIZE, arena);
	else
	{
		ind = get_ind((pl->index + 2) % MEM_SIZE, arena, IND_SIZE);
		tmp = cw_strsub(arena, (pl->index + (ind % IDX_MOD)) % MEM_SIZE, REG_SIZE);
	}
	reg_i = (code[1] == '0') ? (get_regis(arena, (pl->index + 2 + DIR_SIZE) % MEM_SIZE) - 1) % REG_NUMBER : (get_regis(arena, (pl->index + 2 + IND_SIZE) % MEM_SIZE) - 1) % REG_NUMBER;
	ft_memcpy(pl->r[reg_i], tmp, REG_SIZE);
	free(tmp);
	free(code);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	store(t_process *pl, unsigned char *arena)
{
	int		reg_i;
	int		i2;
	char	*code;
	int		count;

	reg_i = (get_regis(arena, (pl->index + 2) % MEM_SIZE) - 1) % REG_NUMBER;
	code = char_to_bit(arena[(pl->index + 1) % MEM_SIZE]);
	if (code[2] == '0')
	{
		i2 = (get_regis(arena, (pl->index + 3) % MEM_SIZE) - 1) % REG_NUMBER;
		ft_memcpy(pl->r[i2], pl->r[reg_i], REG_SIZE);
	}
	else
	{
		count = -1;
		i2 = pl->index + (get_ind((pl->index + 3) % MEM_SIZE, arena, IND_SIZE) % IDX_MOD);
		while (++count < REG_SIZE)
			arena[(i2 + count) % MEM_SIZE] = pl->r[reg_i][count];
	}
	free(code);
}

void	add(t_process *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_ind(0, pl->r[(get_regis(arena, (pl->index + 2) % MEM_SIZE) - 1) % REG_NUMBER], REG_SIZE);
	nb2 = get_ind(0, pl->r[(get_regis(arena, (pl->index + 3) % MEM_SIZE) - 1) % REG_NUMBER], REG_SIZE);
	res = (nb1 + nb2) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->r[(get_regis(arena, (pl->index + 4) % MEM_SIZE) - 1) % REG_NUMBER], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	sub(t_process *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_ind(0, pl->r[(get_regis(arena, (pl->index + 2) % MEM_SIZE) - 1) % REG_NUMBER], REG_SIZE);
	nb2 = get_ind(0, pl->r[(get_regis(arena, (pl->index + 3) % MEM_SIZE) - 1) % REG_NUMBER], REG_SIZE);
	res = (nb1 - nb2) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->r[(get_regis(arena, (pl->index + 4) % MEM_SIZE) - 1) % REG_NUMBER], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

int		get_arg3_pos(unsigned char code)
{
	if ((code & 240) == 80)
		return (4);
	else if ((code & 240) == 96 || (code & 240) == 144)
		return (7);
	else if ((code & 240) == 112 || (code & 240) == 208)
		return (5);
	else if ((code & 240) == 160)
		return (10);
	else if ((code & 240) == 176 || (code & 240) == 224)
		return (8);
	else if ((code & 240) == 240)
		return (6);
	else
		return (-1);
}

int		get_arg3i_pos(unsigned char code)
{
	if ((code & 240) == 80)
		return (4);
	else if ((code & 240) == 96 || (code & 240) == 144)
		return (5);
	else if ((code & 240) == 112 || (code & 240) == 208)
		return (5);
	else if ((code & 240) == 160)
		return (6);
	else if ((code & 240) == 176 || (code & 240) == 224)
		return (6);
	else if ((code & 240) == 240)
		return (6);
	else
		return (-1);
}

int		get_nb(int i, unsigned char *arena, unsigned char code, t_process *pl)
{
	int	index;

	if (code == 4 || code == 16 || code == 64)
		return (get_ind(0, pl->r[(get_regis(arena, i) - 1) % REG_NUMBER], REG_SIZE));
	else if (code == 8 || code == 32 || code == 128)
	{
		if (pl->flag)
			return (get_ind(i, arena, IND_SIZE));
		else
			return (get_ind(i, arena, DIR_SIZE));
	}
	else
	{
		index = get_ind(i, arena, IND_SIZE);
		return (get_ind((pl->index + (index % IDX_MOD)) % MEM_SIZE, arena, IND_SIZE));
	}
}

int		get_lnb(int i, unsigned char *arena, unsigned char code, t_process *pl)
{
	int	index;

	if (code == 4 || code == 16 || code == 64)
		return (get_ind(0, pl->r[(get_regis(arena, i) - 1) % REG_NUMBER], REG_SIZE));
	else if (code == 8 || code == 32 || code == 128)
	{
		if (pl->flag)
			return (get_ind(i, arena, IND_SIZE));
		else
			return (get_ind(i, arena, DIR_SIZE));
	}
	else
	{
		index = get_ind(i, arena, IND_SIZE);
		return (get_ind((pl->index + index) % MEM_SIZE, arena, IND_SIZE));
	}
}

int		get_arg2_pos(unsigned char code)
{
	if ((code & 192) == 64)
		return (3);
	else if ((code & 192) == 128)
		return (6);
	else if ((code & 192) == 192)
		return (4);
	else
		return (-1);
}

int		get_arg2i_pos(unsigned char code)
{
	if ((code & 192) == 64)
		return (3);
	else if ((code & 192) == 128)
		return (4);
	else if ((code & 192) == 192)
		return (4);
	else
		return (-1);
}

void	and(t_process *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_nb(((pl->index + 2) % MEM_SIZE), arena, arena[(pl->index + 1) % MEM_SIZE] & 192, pl);
	nb2 = get_nb((pl->index + get_arg2_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 48, pl);
	res = (nb1 & nb2 ) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->r[(get_regis(arena, (pl->index + get_arg3_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE) - 1) % REG_NUMBER], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	or(t_process *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_nb(((pl->index + 2) % MEM_SIZE), arena, arena[(pl->index + 1) % MEM_SIZE] & 192, pl);
	nb2 = get_nb((pl->index + get_arg2_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 48, pl);
	res = (nb1 | nb2 ) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->r[(get_regis(arena, (pl->index + get_arg3_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE) - 1) % REG_NUMBER], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	xor(t_process *pl, unsigned char *arena)
{
	int		res;
	int		nb1;
	int		nb2;
	char	*tmp;

	nb1 = get_nb(((pl->index + 2) % MEM_SIZE), arena, arena[(pl->index + 1) % MEM_SIZE] & 192, pl);
	nb2 = get_nb((pl->index + get_arg2_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 48, pl);
	res = (nb1 ^ nb2 ) % MEM_SIZE;
	tmp = int_to_bit(res);
	fill_regis(pl->r[(get_regis(arena, (pl->index + get_arg3_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE) - 1) % REG_NUMBER], tmp);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	zjump(t_process *pl, unsigned char *arena)
{
	int	i;

	i = get_ind((pl->index + 1) % MEM_SIZE, arena, IND_SIZE);
	if (pl->carry == 1)
	{
		pl->index += (i % IDX_MOD);
		pl->index %= MEM_SIZE;
	}
}

void	ldi(t_process *pl, unsigned char *arena)
{
	int		index;
	int		i1;
	int		i2;
	int		reg_i;
	char	*tmp;

	pl->flag = 1;
	i1 = get_nb((pl->index + 2) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 192, pl);
	i2 = get_nb((pl->index + get_arg2i_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 48, pl);
	index = (i1 + i2) % IDX_MOD;
	tmp = cw_strsub(arena, (pl->index + index) % MEM_SIZE, REG_SIZE);
	reg_i = (get_regis(arena, (pl->index + get_arg3i_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE) - 1) % REG_NUMBER;
	ft_memcpy(pl->r[reg_i], tmp, REG_SIZE);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
	pl->flag = 0;
}

void	sti(t_process *pl, unsigned char *arena)
{
	int		index;
	int		i1;
	int		i2;
	int		reg_i;
	int		i;

	pl->flag = 1;
	i = -1;
	i1 = get_nb((pl->index + get_arg2i_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 48, pl);
	i2 = get_nb((pl->index + get_arg3i_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 12, pl);
	index = (i1 + i2) % MEM_SIZE;
	reg_i = (get_regis(arena,(pl->index + 2) % MEM_SIZE) - 1) % REG_NUMBER;
	while (++i < 4)
		arena[(i + pl->index + index) % MEM_SIZE] = pl->r[reg_i][i];
	pl->flag = 0;
}

void	forki(t_process *pl, unsigned char *arena)
{
	int		index;
	int		new_i;

	index = get_ind((pl->index + 1) % MEM_SIZE, arena, IND_SIZE);
	new_i = (pl->index + (index % IDX_MOD)) % MEM_SIZE;
	add_node(new_i, pl, pl);
}

void	aff(t_process *pl, unsigned char *arena)
{
	char	*bits;
	int		i;
	unsigned char	c;
	int		reg;
	char	*tmp;
	char	*tmp2;

	i = -1;
	if (!(bits = ft_strnew(0)))
		exit(-1);
	// int fd2 =open("blablabla", O_CREAT | O_RDWR);
	reg = (get_regis(arena, (pl->index + 2) % MEM_SIZE) - 1) % REG_NUMBER;
	// for (int x= 0; x < REG_NUMBER; x++)
	// {
	// 	for (int y = 0; y < 4; y++)
	// 	{
	// 		ft_putchar_fd(pl->r[x][y], fd2);
	// 		ft_putchar_fd('\n', fd2);
	// 	}
	// }
	while (++i < REG_SIZE)
	{
		tmp = char_to_bit(pl->r[reg][i]);
		tmp2 = ft_strjoin(bits, tmp);
		free(bits);
		free(tmp);
		bits = tmp2;
	}
	c = bit_to_dec(bits, REG_SIZE) % 256;
	// close(fd2);
	free(bits);
	mvprintw(34, 202, "aff: %c", c);
// 	mvaddch(0, 0, 0);
}

void	lld(t_process *pl, unsigned char *arena)
{
	char	*tmp;
	int		reg_i;
	char	*code;
	int		ind;

	tmp = NULL;
	code = char_to_bit(arena[(pl->index + 1) % MEM_SIZE]);
	if (code[1] == '0')
		tmp = get_dir((pl->index + 2) % MEM_SIZE, arena);
	else
	{
		ind = get_ind((pl->index + 2) % MEM_SIZE, arena, IND_SIZE);
		tmp = cw_strsub(arena, (pl->index + ind) % MEM_SIZE, REG_SIZE);
	}
	reg_i = (code[1] == '0') ? (get_regis(arena, (pl->index + 2 + DIR_SIZE) % MEM_SIZE) - 1) % REG_NUMBER : (get_regis(arena, (pl->index + 2 + IND_SIZE) % MEM_SIZE) - 1) % REG_NUMBER;
	ft_memcpy(pl->r[reg_i], tmp, REG_SIZE);
	free(tmp);
	free(code);
	pl->carry = (pl->carry) ? 0 : 1;
}

void	lldi(t_process *pl, unsigned char *arena)
{
	int		index;
	int		i1;
	int		i2;
	int		reg_i;
	char	*tmp;

	pl->flag = 1;
	i1 = get_lnb((pl->index + 2) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 192, pl);
	i2 = get_lnb((pl->index + get_arg2i_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE, arena, arena[(pl->index + 1) % MEM_SIZE] & 48, pl);
	index = (i1 + i2) % MEM_SIZE;
	tmp = cw_strsub(arena, (pl->index + index) % MEM_SIZE, REG_SIZE);
	reg_i = (get_regis(arena, (pl->index + get_arg3i_pos(arena[(pl->index + 1) % MEM_SIZE])) % MEM_SIZE) - 1) % REG_NUMBER;
	ft_memcpy(pl->r[reg_i], tmp, REG_SIZE);
	free(tmp);
	pl->carry = (pl->carry) ? 0 : 1;
	pl->flag = 0;
}

void	lfork(t_process *pl, unsigned char *arena)
{
	int		index;
	int		new_i;

	index = get_ind((pl->index + 1) % MEM_SIZE, arena, IND_SIZE);
	new_i = (pl->index + index) % MEM_SIZE;
	add_node(new_i, pl, pl);
	pl->carry = (pl->carry) ? 0 : 1;
}
