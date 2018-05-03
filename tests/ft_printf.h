/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:42:21 by gkuraite          #+#    #+#             */
/*   Updated: 2018/04/19 18:42:26 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_formatcase
{
	int	hash;
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	width;
	int	precision;
	int	size;
	int	type;
	int contentc;
}				t_flags;

int				ft_printf(const char *restrict format, ...);
int				is_valid(t_flags *f);
int				manage_size_flags(const char *restrict *format);
int				get_string(t_flags *f, va_list ap);
int				dofortypeid(t_flags *f, va_list ap);
int				dofortypeo(t_flags *f, va_list ap);
int				dofortypeu(t_flags *f, va_list ap);
int				dofortypex(t_flags *f, va_list ap);
int				dofortypec(t_flags *f, va_list ap);
int				dofortypes(t_flags *f, va_list ap);
int				dofortypep(t_flags *f, va_list ap);
int				dofortypepc(t_flags *f);

#endif
