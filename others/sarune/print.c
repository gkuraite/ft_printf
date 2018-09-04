/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:45:14 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 15:48:46 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static void	send_others(va_list *ap, t_flags *flags, unsigned int *counter)
{
	if (flags->type == TYPE_POINTER)
		*counter += format_pointer(flags, va_arg(*ap, unsigned long int));
	else if (flags->type == TYPE_LONG_CHAR ||
			(flags->type == TYPE_CHAR && flags->size == SIZE_LONG))
		*counter += format_long_char(flags, (wchar_t)va_arg(*ap, long int));
	else if (flags->type == TYPE_LONG_STRING ||
			(flags->type == TYPE_STRING && flags->size == SIZE_LONG))
		*counter += format_long_string(flags, (wchar_t*)va_arg(*ap, wchar_t*));
	else if (flags->type == TYPE_PERCENT)
		*counter += format_percent(flags);
	else if (flags->type == TYPE_STRING && !(flags->size))
		*counter += format_string(flags, va_arg(*ap, char *));
	else if (flags->type == TYPE_CHAR && !(flags->size))
		*counter += format_char(flags, va_arg(*ap, int));
}

static void	send_unsigned(va_list *ap, t_flags *flags, unsigned int *counter)
{
	if (flags->type == TYPE_UNSIGNED && !(flags->size))
		*counter += format_unsigned(flags, va_arg(*ap, unsigned));
	else if (flags->type == TYPE_UNSIGNED && flags->size == SIZE_SIGNED_CHAR)
		*counter += format_unsigned(flags,
				(unsigned char)va_arg(*ap, unsigned int));
	else if (flags->type == TYPE_UNSIGNED && flags->size == SIZE_SHORT)
		*counter += format_unsigned(flags,
				(unsigned short)va_arg(*ap, unsigned int));
	else if ((flags->type == TYPE_UNSIGNED && flags->size == SIZE_LONG) ||
			flags->type == TYPE_UNSIGNED_INT)
		*counter += format_unsigned(flags,
				(unsigned long)va_arg(*ap, unsigned long));
	else if (flags->type == TYPE_UNSIGNED && flags->size == SIZE_LONGLONG)
		*counter += format_unsigned(flags,
				(unsigned long long)va_arg(*ap, unsigned long long));
	else if (flags->type == TYPE_UNSIGNED && flags->size == SIZE_INTMAX)
		*counter += format_unsigned(flags, (uintmax_t)va_arg(*ap, uintmax_t));
	else if (flags->type == TYPE_UNSIGNED && flags->size == SIZE_T)
		*counter += format_unsigned(flags, (size_t)va_arg(*ap, size_t));
}

static void	formatter(va_list *ap, t_flags *flags, unsigned int *counter)
{
	send_integer(ap, flags, counter);
	send_hex_small(ap, flags, counter);
	send_hex_big(ap, flags, counter);
	send_octal(ap, flags, counter);
	send_unsigned(ap, flags, counter);
	send_others(ap, flags, counter);
}

void		do_everything(va_list *ap, t_flags *flags, const char *format,
		unsigned int *counter)
{
	unsigned int		i;

	while (*format)
	{
		if (*format == '%')
		{
			i = 0;
			while (*format)
			{
				i++;
				if ((check_type(*format)) || (*format == '%' && i != 1))
					break ;
				format++;
			}
			formatter(ap, flags, counter);
			flags = flags->next;
		}
		else
		{
			ft_putchar(*format);
			(*counter)++;
		}
		format++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_flags			*flags;
	t_flags			*cpy;
	va_list			ap;
	unsigned int	counter;

	counter = 0;
	flags = fill_flags((char *)format);
	cpy = flags;
	recheck_flags(flags);
	va_start(ap, format);
	do_everything(&ap, flags, format, &counter);
	va_end(ap);
	free_flags(cpy);
	return (counter);
}
