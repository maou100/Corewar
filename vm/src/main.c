/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arnaud <Arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:11:07 by amagnan           #+#    #+#             */
/*   Updated: 2019/02/14 14:06:47 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/vm.h"

void	check_end(t_vm vm)
{
	if (!vm.process)
	{
		write(1, "Player ", 7);
		if (vm.p1->last_live)
			ft_putnbr(get_ind(0, vm.p1->nbr, 4));
		else
			ft_putnbr(get_ind(0, vm.p2->nbr, 4));
		write(1, " (", 2);
		if (vm.p1->last_live)
			ft_putstr(vm.p1->header.prog_name);
		else
			ft_putstr(vm.p2->header.prog_name);
		write(1, ") won\n", 6);
	}
}

int		only_digits(char *str)
{
	int		i;

	i = -1;
	if (!str[i + 1])
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int		check_args(char **argv, int argc)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[++j])
	{
		if (ft_strcmp("-n", argv[j]) && ft_strcmp("-dump", argv[j]) && !ft_strstr(argv[j], ".cor") && !only_digits(argv[j]))
			return (0);
	}
	if (!ft_strcmp(argv[1], "-dump"))
	{
		if (ft_atoi(argv[2]) <= 0 || argc < 5)
			return (0);
		i += 2;
	}
	if (!ft_strcmp(argv[i], "-n"))
	{
		if (!argv[i + 1] || ft_atoi(argv[i + 1]) <= 0)
			return (0);
		i += 2;
	}
	if (!argv[i] || !ft_strstr(argv[i], ".cor"))
		return (0);
	if (!ft_strcmp(argv[++i], "-n"))
	{
		if (!argv[i + 1] || ft_atoi(argv[i + 1]) <= 0)
			return (0);
		i += 2;
	}
	if (!argv[i] || !ft_strstr(argv[i], ".cor") || argv[i + 1])
		return (0);
	return (1);
}

void	free_all(t_vm *vm)
{
	t_process	*tmp;
	int			i;

	i = -1;
	if (vm)
	{
		if (vm->p1)
		{
			if (vm->p1->nbr)
				free(vm->p1->nbr);
			free(vm->p1);
		}
		if (vm->p2)
		{
			if (vm->p2->nbr)
				free(vm->p2->nbr);
			free(vm->p2);
		}
		while (vm->process)
		{
			tmp = vm->process;
			vm->process = vm->process->next;
			if (tmp->r)
			{
				while (++i < REG_NUMBER)
				{
					if (tmp->r[i])
						free(tmp->r[i]);
				}
				free(tmp->r);
			}
			free(tmp);
		}
		if (vm->arena)
			free(vm->arena);
	}
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	if (argc < 3 || !check_args(argv, argc))
		ft_exit_msg("./corewar [-dump nbr_cycles(>0)] [[-n(>0) number] champion1.cor] [[-n(>0) number] champion1.cor]\n");
	vm = get_vm(argv, NULL);
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	if (argc > 2)
		start_vm(&vm);
	endwin();
	check_end(vm);
	free_all(&vm);
	return (0);
}
