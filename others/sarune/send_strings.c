/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:54:18 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 16:54:22 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	send_integer(va_list *ap, t_flags *flags, unsigned int *counter)
{
	if (flags->type == TYPE_INTEGER && !(flags->size))
		*counter += format_integer(flags, va_arg(*ap, int));
	else if ((flags->type == TYPE_INTEGER && flags->size == SIZE_LONG)
			|| flags->type == TYPE_BIG_D)
		*counter += format_integer(flags, va_arg(*ap, long int));
	else if (flags->type == TYPE_INTEGER && flags->size == SIZE_LONGLONG)
		*counter += format_integer(flags, va_arg(*ap, long long int));
	else if (flags->type == TYPE_INTEGER && flags->size == SIZE_SHORT)
		*counter += format_integer(flags, (short)va_arg(*ap, int));
	else if (flags->type == TYPE_INTEGER && flags->size == SIZE_SIGNED_CHAR)
		*counter += format_integer(flags, (char)va_arg(*ap, int));
	else if (flags->type == TYPE_INTEGER && flags->size == SIZE_INTMAX)
		*counter += format_integer(flags, (intmax_t)va_arg(*ap, intmax_t));
	else if (flags->type == TYPE_INTEGER && flags->size == SIZE_T)
		*counter += format_integer(flags, (size_t)va_arg(*ap, size_t));
}

void	send_hex_small(va_list *ap, t_flags *flags, unsigned int *counter)
{
	if (flags->type == TYPE_HEX && !(flags->size))
		*counter += format_hex(flags, va_arg(*ap, unsigned int), FALSE);
	else if (flags->type == TYPE_HEX && flags->size == SIZE_SHORT)
		*counter += format_hex(flags,
				(unsigned short)va_arg(*ap, unsigned int), FALSE);
	else if (flags->type == TYPE_HEX && flags->size == SIZE_LONG)
		*counter += format_hex(flags,
				(unsigned long)va_arg(*ap, unsigned long), FALSE);
	else if (flags->type == TYPE_HEX && flags->size == SIZE_LONGLONG)
		*counter += format_hex(flags,
				(unsigned long long)va_arg(*ap, unsigned long long), FALSE);
	else if (flags->type == TYPE_HEX && flags->size == SIZE_SIGNED_CHAR)
		*counter += format_hex(flags,
				(unsigned char)va_arg(*ap, unsigned int), FALSE);
	else if (flags->type == TYPE_HEX && flags->size == SIZE_INTMAX)
		*counter += format_hex(flags,
				(uintmax_t)va_arg(*ap, uintmax_t), FALSE);
	else if (flags->type == TYPE_HEX && flags->size == SIZE_T)
		*counter += format_hex(flags, (size_t)va_arg(*ap, size_t), FALSE);
}

void	send_hex_big(va_list *ap, t_flags *flags, unsigned int *counter)
{
	if (flags->type == TYPE_HEX_BIG && !(flags->size))
		*counter += format_hex(flags, va_arg(*ap, unsigned int), TRUE);
	else if (flags->type == TYPE_HEX_BIG && flags->size == SIZE_SHORT)
		*counter += format_hex(flags,
				(unsigned short)va_arg(*ap, unsigned int), TRUE);
	else if (flags->type == TYPE_HEX_BIG && flags->size == SIZE_LONG)
		*counter += format_hex(flags,
				(unsigned long)va_arg(*ap, unsigned long), TRUE);
	else if (flags->type == TYPE_HEX_BIG && flags->size == SIZE_LONGLONG)
		*counter += format_hex(flags,
				(unsigned long long)va_arg(*ap, unsigned long long), TRUE);
	else if (flags->type == TYPE_HEX_BIG && flags->size == SIZE_SIGNED_CHAR)
		*counter += format_hex(flags,
				(unsigned char)va_arg(*ap, unsigned int), TRUE);
	else if (flags->type == TYPE_HEX_BIG && flags->size == SIZE_INTMAX)
		*counter += format_hex(flags, (uintmax_t)va_arg(*ap, uintmax_t), TRUE);
	else if (flags->type == TYPE_HEX_BIG && flags->size == SIZE_T)
		*counter += format_hex(flags, (size_t)va_arg(*ap, size_t), TRUE);
}

void	send_octal(va_list *ap, t_flags *flags, unsigned int *counter)
{
	if (flags->type == TYPE_OCT && !(flags->size))
		*counter += format_octal(flags, va_arg(*ap, unsigned int));
	else if (flags->type == TYPE_UNSIGNED_OCT)
		*counter += format_octal(flags, va_arg(*ap, unsigned long));
	else if (flags->type == TYPE_OCT && flags->size == SIZE_SIGNED_CHAR)
		*counter += format_octal(flags,
				(unsigned char)va_arg(*ap, unsigned int));
	else if (flags->type == TYPE_OCT && flags->size == SIZE_SHORT)
		*counter += format_octal(flags,
				(unsigned short)va_arg(*ap, unsigned int));
	else if (flags->type == TYPE_OCT && flags->size == SIZE_LONG)
		*counter += format_octal(flags,
				(unsigned long)va_arg(*ap, unsigned long));
	else if (flags->type == TYPE_OCT && flags->size == SIZE_LONGLONG)
		*counter += format_octal(flags,
				(unsigned long long)va_arg(*ap, unsigned long long));
	else if (flags->type == TYPE_OCT && flags->size == SIZE_INTMAX)
		*counter += format_octal(flags, (uintmax_t)va_arg(*ap, uintmax_t));
	else if (flags->type == TYPE_OCT && flags->size == SIZE_T)
		*counter += format_octal(flags, (size_t)va_arg(*ap, size_t));
}
