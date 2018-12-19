/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:54:46 by feedme            #+#    #+#             */
/*   Updated: 2018/12/16 00:07:57 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_player	*player_init(void)
{
	t_player	*new;
	int			i;

	i = -1;
	if (!(new = (t_player*)malloc(sizeof(t_player))))
		ft_exit_msg("Malloc failed\n");
	new->lifec = 0;
	new->i = 0;
	new->carry = 0;
	new->next = NULL;
	if (!(new->regs = (unsigned char**)malloc(sizeof(unsigned char*) * REG_NUMBER)))
		ft_exit_msg("Malloc failed\n");
	while (++i < REG_NUMBER)
	{
		if (!(new->regs[i] = (unsigned char*)malloc(REG_SIZE)))
			ft_exit_msg("Malloc failed\n");
		ft_bzero(new->regs[i], REG_SIZE);
	}
	return (new)
}

int		main(int ac, char **av)
{
	unsigned char		*arena;

	if (ac < 3)
		ft_exit_msg("Corewar needs at least 2 champions\n");
	if (!(arena = (unsigned char*)malloc(MEM_SIZE)))
		ft_exit_msg("Malloc failed\n");
	ft_bzero(arena, MEM_SIZE);
	return (0);
}
