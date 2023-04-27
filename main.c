#include "debug.h"

int	main(int argc, char **argv)
{
	char	*s = argv[0];
	int		x = 5;

	debug_leaks();
	printf("Programa de prueba\n\n");
	print_debug("DEBUG> El valor de x es %i\n\n", x);
	printf("La depuración está %s\n\n", DEBUG? "activada" : "desactivada");
	print_debug("DEBUG> El valor de s es %s\n\n", s);
	printf("Fin del programa\n\n");
	print_debug("DEBUG> Se alcanzó el final del programa\n");
	return (0);
}
