/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:56:07 by feedme            #+#    #+#             */
/*   Updated: 2018/12/15 18:08:40 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"

# define MAX_UINT 4294967295

typedef struct		s_player;
{
	int				cyclec;
	int				lifec;
	int				i;
	unsigned char	**regs;
	char			carry;
	struct s_player	*next;
}				t_player;

#endif
