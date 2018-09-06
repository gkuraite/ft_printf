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
# include <limits.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	const char	*format;
	int		i;

	int		is_flag;
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
void	check_flags(t_flags *f);
void	check_width(t_flags *f);
void    check_precision(t_flags *f);
void    check_size(t_flags *f);
void    printf_errors(int error_num);

void 	is_it_valid(t_flags *f);

int 	d_conversion(t_flags *f, va_list *ap);


#endif