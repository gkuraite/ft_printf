/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:33:56 by gkuraite          #+#    #+#             */
/*   Updated: 2018/07/25 10:20:18 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/includes/libft.h"

typedef struct		s_flags
{
	int		plus;
	int		minus;
	int		hash;
	int		zero;
	int		space;
	int		width;
	int		precision;
	int		size;
	int		type;

	
}					t_flags;

int		ft_printf(const char *restrict format, ...);

#endif
