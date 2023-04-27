#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG 0

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_exit(void);

void	debug_leaks(void);

void	print_debug(char *message, ...);

#endif