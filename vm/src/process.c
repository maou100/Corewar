/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:42:33 by amagnan           #+#    #+#             */
/*   Updated: 2019/02/15 14:51:51 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

t_process			*make_node(int id)
{
	t_process		*process;
	int				i;

	i = -1;
	if (!(process = (t_process*)malloc(sizeof(t_process))) || !(process->r = (unsigned char**)malloc(sizeof(unsigned char*) * REG_NUMBER)))
		ft_exit_msg("malloc failed\n");
	while (++i < REG_NUMBER)
	{
		if (!(process->r[i] = (unsigned char*)malloc(REG_SIZE)))
			ft_exit_msg("malloc failed\n");
		ft_bzero(process->r[i], REG_SIZE);
	}
	process->id = id;
	process->c_to_wait = 0;
	process->nlive = 0;
	process->index = 0;
	process->carry = 0;
	process->flag = 0;
	process->next = NULL;
	return (process);
}

void				add_node(int index, t_process *head, t_process *copy)
{
	t_process		*current;
	int 			i;

	i = -1;
	current = head;
	while (current && current->next)
		current = current->next;
	current->next = make_node(current->id + 1);
	current = current->next;
	while (++i < REG_NUMBER)
		ft_memcpy(current->r[i], copy->r[i], REG_SIZE);
	current->c_to_wait = copy->c_to_wait;
	current->nlive = copy->nlive;
	current->carry = copy->carry;
	current->index = index;
	current->next = NULL;
}

void				delete_node(t_process *head, int id)
{
	t_process		*current;
	t_process		*tmp;

	current = head;
	while (current && current->next && current->next->id != id)
		current = current->next;
	tmp = current->next;
	if (current->next)
	{
		current->next = current->next->next;
		free(tmp);
	}
}
