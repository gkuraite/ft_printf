/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:12:52 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 14:48:46 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

# define TRUE 				1
# define FALSE 				0

# define TYPE_INTEGER		1
# define TYPE_STRING		2
# define TYPE_POINTER		3
# define TYPE_SIGNED_INT	4
# define TYPE_OCT			5
# define TYPE_UNSIGNED_OCT	6
# define TYPE_UNSIGNED		7
# define TYPE_UNSIGNED_INT	8
# define TYPE_HEX			9
# define TYPE_HEX_BIG		10
# define TYPE_CHAR			11
# define TYPE_LONG_CHAR		12
# define TYPE_LONG_STRING	13
# define TYPE_BIG_D			14
# define TYPE_PERCENT		15

# define SIZE_SHORT			1
# define SIZE_LONG			2
# define SIZE_LONGLONG		3
# define SIZE_SIGNED_CHAR	4
# define SIZE_INTMAX		5
# define SIZE_T				6

# define ABS(Value) (Value < 0 ? -Value : Value)

typedef int			t_bool;

typedef struct		s_flags
{
	int				hashtag;
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				width;
	int				precision;
	int				dot;
	int				size;
	int				type;
	struct s_flags	*next;
}					t_flags;

int					ft_printf(const char *format, ...);
t_bool				check_line(const char *src);
t_flags				*fill_flags(char *str);
t_bool				check_type(char c);
void				ft_set_flags(char *str, t_flags *flag);
void				ft_set_size(char *str, t_flags *flag);
void				ft_set_width(char *str, t_flags *flag);
void				ft_set_type(char **str, t_flags *flag);
int					format_integer(t_flags *flag, long long int nbr);
void				fill_with_char(int space, char c);
int					format_string(t_flags *flag, char *str);
int					format_char(t_flags *flag, char c);
int					format_hex(t_flags *flag, unsigned long long hex,
		t_bool hex_case);
int					format_pointer(t_flags *flag, unsigned long int ptr);
int					format_octal(t_flags *flag, unsigned long long octal);
int					format_unsigned(t_flags *flag, unsigned long long nbr);
void				recheck_flags(t_flags *flags);
int					format_long_char(t_flags *flag, long int c);
int					format_long_string(t_flags *flag, wchar_t *str);
int					format_percent(t_flags *flag);
void				free_flags(t_flags *flag);
void				flag_type(char **str, t_flags *flag);
void				send_integer(va_list *ap, t_flags *flag,
		unsigned int *counter);
void				send_hex_small(va_list *ap, t_flags *flag,
		unsigned int *counter);
void				send_hex_big(va_list *ap, t_flags *flag,
		unsigned int *counter);
void				send_octal(va_list *ap, t_flags *flag,
		unsigned int *counter);

#endif
