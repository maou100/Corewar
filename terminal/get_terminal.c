#include "term.h"

t_term		get_terminal(void)
{
	static t_term	terminal;
	struct termios  termios;
	struct termios  old_termios;

	if (terminal.def != -1)
	{
		terminal.def = -1;
		tgetent(NULL, getenv("TERM"));
		tcgetattr(0, &old_termios);
		tcgetattr(0, &termios);
		terminal.old_term = old_termios;
		terminal.new_term = termios;
		ioctl(STDERR_FILENO, TIOCGWINSZ, &terminal.win_size);
	}
	return (terminal);
}
