/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_cconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:32:42 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/28 08:32:53 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*four_bytes(wchar_t c)
{
	char	*reply;

	reply = ft_strnew(4);
	reply[0] = (c >> 18) + 240;
	reply[1] = ((c >> 12) & 63) + 128;
	reply[2] = ((c >> 6) & 63) + 128;
	reply[3] = (c & 63) + 128;
	return (reply);
}

static char	*three_bytes(wchar_t c)
{
	char	*reply;

	reply = ft_strnew(3);
	reply[0] = (c >> 12) + 224;
	reply[1] = ((c >> 6) & 63) + 128;
	reply[2] = (c & 63) + 128;
	return (reply);
}

static char	*two_bytes(wchar_t c)
{
	char	*reply;

	reply = ft_strnew(2);
	reply[0] = (c >> 6) + 192;
	reply[1] = (c & 63) + 128;
	return (reply);
}

char		*wide_cconvert(wchar_t c)
{
	char	*reply;

	if (c < 2047)
		reply = two_bytes(c);
	else if (c < 65535)
		reply = three_bytes(c);
	else
		reply = four_bytes(c);
	return (reply);
}
