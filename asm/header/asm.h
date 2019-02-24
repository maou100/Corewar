/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 00:32:40 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/05 00:32:41 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/libft.h"
# include "../../op/op.h"

typedef struct 		s_op
{
	char			*command;
	int				nb_arg;
	int				arg_type[3];
	int				op_code;
	int				nb_cycle;
	char			*lcommand;
	char			coding_byte;
	char			size;
}					t_op;

typedef struct 		s_label
{
	char			*label;
	int				*tab;
	int				*offset;
	int				argc;
	int				index;
	char			found;
	struct s_label	*next;
}					t_label;

typedef struct 		s_asm
{
	char			*buf;
	char			*name;
	char			*comment;
	int 			*codes;
	int 			index;
	t_label 		*label;
}					t_asm;

typedef struct 		s_code
{
	char			*binaire;
	struct s_code	*next;
	struct s_code	*prev;
}					t_code;

t_op    			op_tab[17];

/*
**		label.c
*/

t_label 			*make_new_label(void);
void				add_label(char *tmp, int index, t_label **label);
int 				get_label(t_asm *data);
void				ft_add_index_to_label(int index, int real_index, char *name, t_label **label, int size);

/*
**		parser.c
*/

int 				ft_check_if_command(char *tmp);
int					ft_is_label(char c, int code);
int					ft_get_value(char *tmp, int *codes, int index, int label);
int 				get_second_byte(int *codes, int index, int *label);

/*
**		process.c
*/

void				get_name(t_asm *data);
void				get_comment(t_asm *data);

/*
**		main.c
*/

int					get_codes(char *buf, int *codes, int index, t_label **label);

#endif
