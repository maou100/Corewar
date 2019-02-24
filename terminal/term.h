#ifndef TERM_H
# define TERM_H

# include <termios.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

typedef	struct			s_term
{
	struct termios		old_term;
	struct termios		new_term;
	struct winsize		win_size;
	int 				def;
	int 				max_col;
	int 				max_row;
}						t_term;

int						ft_putint(int c);
void					terminal_off(t_term *terminal);
void					terminal_on(t_term *terminal);
t_term					get_terminal(void);
void					ft_quit(t_term *terminal);
void					receive_key(t_term *terminal);
int						get_size(t_term *term);

# define ENTER					10
# define ESC_KEY				27
# define SPACE_KEY				32
# define LEFT_KEY				4479771
# define UP_KEY					4283163
# define RIGHT_KEY				4414235
# define DOWN_KEY				4348699
# define DEL_KEY				2117294875
# define BACKSPACE				127
# define O_KEY					111

#endif