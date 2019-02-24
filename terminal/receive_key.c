#include "term.h"

void		receive_key(t_term *terminal)
{
	int		buf;

	buf = 0;
	read(0, &buf, 4);
	tputs(tgetstr("cl", NULL), 1, ft_putint);
	if (buf == ESC_KEY)
		ft_quit(terminal);
	// else if (is_move(buf))
	// 	ft_move(buf, terminal);
	// else if (buf == SPACE_KEY)
	// 	select_elem(terminal);
	// else if (buf == ENTER)
	// 	output_and_quit(terminal);
	// else if (buf == DEL_KEY || buf == BACKSPACE)
	// 	erase_elem(&g_terminal);
}
