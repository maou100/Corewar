#include "term.h"

void		ft_quit(t_term *term)
{
	terminal_off(term);
	exit(0);
}