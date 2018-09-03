/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:02:34 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/03 17:02:37 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isdigit(int c)
{
	while (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int		ft_intlen(int nb)
{
	int		index;

	index = 0;
	if (nb <= 0)
		index++;
	while (nb)
	{
		index++;
		nb = nb / 10;
	}
	return (index);
}

static char	*ft_strdup(const char *src)
{
	int		i;
	int		range;
	char	*str;

	if (!src)
		return (NULL);
	range = 0;
	i = 0;
	while (src[range])
		range++;
	str = (char*)malloc(sizeof(*str) * (range + 1));
	if (str == NULL)
		return (NULL);
	while (i < range)
	{
		str[i] = src[i];
		i++;
	}
	str[range] = '\0';
	return (str);
}


static char			*ft_itoa(int n)
{
	char	*str;
	int		index;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	index = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_intlen(n) + 1))))
		return (NULL);
	str[index] = '\0';
	index = ft_intlen(n) - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		*str = '0';
	while (n > 0)
	{
		str[index] = '0' + (n % 10);
		n = n / 10;
		index--;
	}
	return (str);
}

void        ft_check_width(t_flags *form)
{
    if (isdigit(form->format))
        form->width = ft_itoa(form->format[form->i]);
}