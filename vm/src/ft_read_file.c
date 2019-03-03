/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:58:34 by amagnan           #+#    #+#             */
/*   Updated: 2019/02/14 17:14:13 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

static void			initialize_players(t_player *p1, t_player *p2)
{
	p1->last_live = 0;
	p1->nlive = 0;
	p1->talk = 0;
	p1->fd = 0;
	p1->nbr = NULL;
	p2->last_live = 0;
	p2->nlive = 0;
	p2->talk = 0;
	p2->fd = 0;
	p2->nbr = NULL;
}

static void			make_process(t_vm *vm)
{
	vm->process = make_node(0);
	vm->process->next = make_node(1);
}

void				initialize_process(t_vm *vm)
{
	vm->process->index = 0;
	vm->process->c_to_wait = op_tab[vm->arena[vm->process->index] - 1].nb_cycle;
	vm->process->next->index = MEM_SIZE / 2;
	vm->process->next->c_to_wait = op_tab[vm->arena[vm->process->next->index] - 1].nb_cycle;
}

unsigned char	*build_nbr(int nb)
{
	int				i;
	int				j;
	char	*bits;
	unsigned char	*nbr;


		// int fd2 =open("blablabla", O_CREAT | O_RDWR | O_APPEND);
		// ft_putnbr_fd(nb, fd2);
		// close(fd2);
		// int fd2 =open("blablabla", O_CREAT | O_RDWR | O_APPEND);
		// ft_putnbr_fd(nb, fd2);
		// ft_putstr_fd(", ", fd2);
		// close(fd2);
	if (!(nbr = (unsigned char*)malloc(4)))
		exit(-1);
	bits = int_to_bit(nb);
	i = 24;
	j = 3;
	while (i > -1)
	{
		nbr[j] = bit_to_dec(bits + i, 1);
		i -= 8;
		j--;
	}
	free(bits);
	return (nbr);
}

void			ft_get_file(char **argv, t_vm *vm)
{
	int		i;
	int		nbr1;
	int		nbr2;

	nbr1 = 1;
	nbr2 = 2;
	i = 1;
	if (!ft_strcmp(argv[1], "-dump"))
	{
		  vm->nbr_cycles = ft_atoi(argv[2]);
		  i += 2;
	}
	if (!ft_strcmp(argv[i], "-n"))
	{
		nbr1 = ft_atoi(argv[i + 1]);
		i += 2;
	}
	vm->p2->filename = (unsigned char*)argv[i];
	if (!ft_strcmp(argv[++i], "-n"))
	{
		nbr2 = ft_atoi(argv[i + 1]);
		i += 2;
	}
	vm->p1->filename = (unsigned char*)argv[i];
	vm->p1->nbr = build_nbr(nbr2);
		// int fd2 =open("blablabla", O_CREAT | O_RDWR | O_APPEND);
		// ft_putnbr_fd(nbr1, fd2);
		// ft_putstr_fd(", ", fd2);
		// ft_putnbr_fd(nbr2, fd2);
		// close(fd2);
	vm->p2->nbr = build_nbr(nbr1);
	ft_memcpy(vm->process->r[0], vm->p1->nbr, 4);
	ft_memcpy(vm->process->next->r[0], vm->p2->nbr, 4);
}

unsigned char		*ft_read_files(char **argv, t_vm *vm)
{
	unsigned char	*arena;

	initialize_players(vm->p1, vm->p2);
	make_process(vm);
	arena = (unsigned char *)ft_strnew(MEM_SIZE - 1);
	ft_get_file(argv, vm);
	if (((vm->p1->fd = open((char*)vm->p1->filename, O_RDONLY)) < 0)
		|| (vm->p2->fd = open((char*)vm->p2->filename, O_RDONLY)) < 0)
		ft_exit_msg("File can't be open\n");
	if (!ft_get_player(vm->p1, arena) || !ft_get_player(vm->p2, arena + (MEM_SIZE / 2)))
		ft_exit_msg("File error\n");
	if (close(vm->p1->fd) == -1 || close(vm->p2->fd) == -1)
		ft_exit_msg("Close failed\n");
	return (arena);
}
