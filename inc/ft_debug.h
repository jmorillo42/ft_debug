/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:09:45 by jmorillo          #+#    #+#             */
/*   Updated: 2023/07/23 13:23:57 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

# ifndef DEBUG
#  define DEBUG 1
# endif

# ifndef OUTPUT
#  define OUTPUT "a.out"
# endif

# define DEBUG_COLOR "\e[3;36m"
# define DEBUG_RESET "\e[0;0m"
# define LEAKS_COLOR "\e[35m"

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

void	enable_debug(void);
void	disable_debug(void);
int		is_debug_enabled(void);

void	debug_leaks(void);

void	print_debug(char *message, ...);

#endif
