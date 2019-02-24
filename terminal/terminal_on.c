#include "term.h"

void		terminal_on(t_term *terminal)
{
	terminal->new_term.c_lflag &= ~(ICANON);
	terminal->new_term.c_lflag &= ~(ECHO);
	terminal->new_term.c_cc[VMIN] = 1;
	terminal->new_term.c_cc[VTIME] = 100;
	tcsetattr(0, TCSADRAIN, &terminal->new_term);
	tputs(tgetstr("vi", NULL), 0, ft_putint);
	tputs(tgetstr("ti", NULL), 0, ft_putint);
}
