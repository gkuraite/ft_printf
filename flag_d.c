/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:33:42 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/03 11:33:43 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static size_t		ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s + ft_strlen(s);
	while (*str != (char)c)
	{
		if (str == s)
			return (NULL);
		str--;
	}
	return (str);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);	
}

void	ft_putnbr(int n)
{
	long int	nb;
	char		str;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	str = nb % 10 + '0';
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(str);
}

int     flag_d(t_flags *flags, va_list *ap)
{
    int num;

    num = (int)va_arg(*ap, int);
    ft_putnbr(num);
    return (0);
}