/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:12:28 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 13:49:17 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <locale.h>
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef struct		s_tab
{
	int		minus;
	int		plus;
	int		space;
	int		sharp;
	int		zero;
	int		width;
	int		precision;
	int		h;
	int		l;
	int		j;
	int		z;
	char	*string;
	char	*reply;
	char	*specifier_tab;
	char	*flag_tab;
	va_list	*ap;
}					t_tab;

int					ft_printf(const char *format, ...);
t_tab				init_flags(t_tab tab);
t_tab				solver(t_tab tab);
t_tab				solver(t_tab tab);
t_tab				read_string(t_tab tab);
t_tab				read_flags(t_tab tab);
t_tab				convert_arguments(t_tab tab);
t_tab				cconvert(t_tab tab);
t_tab				sconvert(t_tab tab);
t_tab				wide_sconvert(t_tab tab);
t_tab				dconvert(t_tab tab);
t_tab				pconvert(t_tab tab);
t_tab				oconvert(t_tab tab);
t_tab				uconvert(t_tab tab);
t_tab				xconvert(t_tab tab);
t_tab				cconvert(t_tab tab);
t_tab				bconvert(t_tab tab);
t_tab				fconvert(t_tab tab);
t_tab				percent_convert(t_tab tab);
t_tab				longer_int(t_tab tab);
uintmax_t			get_unsigned(t_tab tab);
char				*hexa_width(char *hexa, t_tab tab);
char				*sign_checker(char *str, t_tab tab);
char				*width_converter(char *str, t_tab tab);
char				*ft_itoa_base(uintmax_t num, int base);
char				*ft_lltoa_base(intmax_t num, int base);
char				*string_precision(char *str, int precision);
char				*precision_solver(char *str, int precision);
char				*width_parser(char *str, t_tab tab);
t_tab				reset_flags(t_tab tab);
char				*move_char(char *str, size_t i);
char				*ft_realloc(char *str, size_t size);
char				*wide_cconvert(wchar_t c);

#endif
