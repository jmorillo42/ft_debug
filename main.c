#include "debug.h"

int	main(int argc, char **argv)
{
	char	*s = argv[0];
	int		x = 42;

	debug_leaks();
	printf("Programa de prueba\n");
	printf("La depuración está %s\n", DEBUG? "activada" : "desactivada");
	print_debug("(DEBUG) El valor de x es %i\n", x);
	print_debug("(DEBUG) El valor de s es %s\n", s);
	print_debug("(DEBUG) Se alcanzó el final del programa\n");
	printf("Fin del programa\n\n");
	return (0);
}
