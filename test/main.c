/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:19:14 by jmorillo          #+#    #+#             */
/*   Updated: 2023/07/23 13:28:12 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_debug.h"

int	main(int argc, char **argv)
{
	char	result[256];

	debug_leaks();
	printf("Programa de prueba de ft_debug\n");
	printf("  El programa concatena el texto de los dos argumentos pasados\n");
	printf("  por línea de comandos. Si el número de argumentos es distinto\n");
	printf("  de dos, muestra un error.\n");
	printf("  Si la depuración está activada, se imprimen los textos de\n");
	printf("  depuración en cian y cursiva. En este programa se muestran\n");
	printf("  el número de argumentos y, a continuación, sus valores. Al\n");
	printf("  finalizar también se comprueba si hay fugas de memoria.\n\n");
	printf("  La depuración está %s\n",
		is_debug_enabled() ? "activada" : "desactivada");
	if (argc != 3)
	{
		print_debug("  (DEBUG) Número de argumentos = %i\n", argc - 1);
		printf("  Error: Número de argumentos incorrecto\n");
	}
	else
	{
		print_debug("  (DEBUG) Los argumentos son:\n");
		for (int i = 1; i < argc; i++)
		{
			print_debug("    (DEBUG) - %s\n", argv[i]);
		}
		strcpy(result, argv[1]);
		strcat(result, argv[2]);
		printf("  El resultado es: %s\n", result);
	}
	printf("Fin del programa\n\n");
}
