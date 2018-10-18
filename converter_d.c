/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:31:18 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 16:51:52 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		converter_d(t_flags *f, va_list *ap)
{
	intmax_t	num;
	char		*str;
	int			len;

	num = convert_size_d(*ap, f);
	str = ft_intmaxtoa(num);
	str = handle_precision_d(f, str);
	str = handle_sign_d(f, str);
	str = handle_width_d(f, str);
	str = handle_position_d(f, str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
