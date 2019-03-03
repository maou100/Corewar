/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arnaud <Arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:10:01 by amagnan           #+#    #+#             */
/*   Updated: 2019/02/15 00:50:37 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../../libft/libft.h"
# include "../../op/op.h"
# include <ncurses.h>

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct 		s_process
{
	int				id;
	int				c_to_wait;
	unsigned char	**r;
	int				nlive;
	unsigned int	index;
	int				carry;
	int				flag;
	struct s_process	*next;
}					t_process;

typedef struct 		s_player
{
	header_t		header;
	int				talk;
	int				nlive;
	int				fd;
	unsigned char	*nbr;
	int				last_live;
	unsigned char	*filename;
}					t_player;

typedef struct 		s_vm
{
	t_player		*p1;
	t_player		*p2;
	t_process		*process;
	// t_term			term;
	unsigned char	*arena;
	int				cycle_to_die;
	int				tcycle;
	int				cycle;
	int				checks;
	int				nlive;
	int				nbr_cycles;
}					t_vm;

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

t_op    			op_tab[17];
typedef void		(*t_fcts)(t_process*, unsigned char*);

void				free_all(t_vm *vm);
unsigned char		*ft_read_files(char **argv, t_vm *vm);
int					ft_get_player(t_player *p, unsigned char *arena);
t_process			*make_node(int id);
void				add_node(int index, t_process *head, t_process *copy);
void				delete_node(t_process *head, int id);
void				start_vm(t_vm *vm);
t_vm				get_vm(char **argv, t_vm *new);
void				initialize_process(t_vm *vm);
void				output_arena(t_vm *vm);

void				live(t_process *pl, unsigned char *arena, t_vm *vm);
void				load(t_process *pl, unsigned char *arena);
void				store(t_process *pl, unsigned char *arena);
void				add(t_process *pl, unsigned char *arena);
void				sub(t_process *pl, unsigned char *arena);
void				and(t_process *pl, unsigned char *arena);
void				or(t_process *pl, unsigned char *arena);
void				xor(t_process *pl, unsigned char *arena);
void				zjump(t_process *pl, unsigned char *arena);
void				ldi(t_process *pl, unsigned char *arena);
void				sti(t_process *pl, unsigned char *arena);
void				forki(t_process *pl, unsigned char *arena);
void				aff(t_process *pl, unsigned char *arena);
void				lld(t_process *pl, unsigned char *arena);
void				lldi(t_process *pl, unsigned char *arena);
void				lfork(t_process *pl, unsigned char *arena);

char				*char_to_bit(unsigned char c);
void				fill_regis(unsigned char *reg, char *bits);
char				*int_to_bit(int c);
char				*get_dir(int i, unsigned char *arena);
int					ft_powof2(int pow);
int					bit_to_dec(char *str, int size);
int					get_ind(int i, unsigned char *arena, int size);
int					get_regis(unsigned char *arena, int i);
int					validate_codingbyte(unsigned char op_code, unsigned char c_byte);




#endif