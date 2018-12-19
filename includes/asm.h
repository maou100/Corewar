/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:18:32 by feedme            #+#    #+#             */
/*   Updated: 2018/12/10 23:40:32 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"

typedef struct			s_labels
{
	char				*label;
	int					*tab;
	int					index;
	char				found;
	struct s_labels		*next;
}						t_labels;

typedef struct			s_asm
{
	int					code_len;
	int					i_g;
	char				*name;
	char				*comment;
	char				*line;
	char				*outp;
	t_labels			*labs;
	int					instr;
}						t_asm;

#endif
