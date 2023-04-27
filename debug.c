#include "debug.h"

void	ft_exit(void)
{
	system("leaks debug");
}

void	debug_leaks(void)
{
	if (DEBUG)
		atexit(ft_exit);
}

void	print_debug(char *message, ...)
{
	va_list args;
	if (DEBUG)
	{
	    va_start(args, message);
	    vprintf(message, args);
	    va_end(args);
	}
}
