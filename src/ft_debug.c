/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:09:55 by jmorillo          #+#    #+#             */
/*   Updated: 2023/07/23 12:56:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_debug.h"

int	g_debug = DEBUG;

static void	ft_exit(void);

void	enable_debug(void)
{
	g_debug = 1;
}

void	disable_debug(void)
{
	g_debug = 0;
}

int	is_debug_enabled(void)
{
	return (g_debug != 0);
}

void	debug_leaks(void)
{
	if (is_debug_enabled())
		atexit(ft_exit);
}

void	print_debug(char *message, ...)
{
	va_list	args;

	if (is_debug_enabled())
	{
		printf("%s", DEBUG_COLOR);
		va_start(args, message);
		vprintf(message, args);
		va_end(args);
		printf("%s", DEBUG_RESET);
		fflush(stdout);
	}
}

static void	ft_exit(void)
{
	char	leaks_cmd[128];

	strcpy(leaks_cmd, "echo ");
	strcat(leaks_cmd, LEAKS_COLOR);
	strcat(leaks_cmd, " && ");
	strcat(leaks_cmd, "leaks -q ");
	strcat(leaks_cmd, OUTPUT);
	system(leaks_cmd);
}
