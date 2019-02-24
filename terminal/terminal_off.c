#include "term.h"

void			terminal_off(t_term *terminal)
{
	tputs(tgetstr("cl", NULL), 1, ft_putint);
	tcsetattr(0, TCSADRAIN, &terminal->old_term);
	tputs(tgetstr("ve", NULL), 0, ft_putint);
	tputs(tgetstr("te", NULL), 0, ft_putint);
}
