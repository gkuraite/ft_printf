/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mbstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:52:11 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/26 14:49:35 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mbstr(wchar_t wc)
{
	char	*wcs;

	wcs = ft_strnew(4);
	if ((wc <= 0x7f && MB_CUR_MAX >= 1) || (wc <= 0xff && MB_CUR_MAX == 1))
		wcs[0] = (char)wc;
	else if (wc <= 0x7ff && MB_CUR_MAX >= 2)
	{
		wcs[0] = (char)((wc >> 6) | 0xc0);
		wcs[1] = (char)((wc & 0x3f) | 0x80);
	}
	else if (wc <= 0xffff && MB_CUR_MAX >= 3)
	{
		wcs[0] = (char)((wc >> 12) | 0xe0);
		wcs[1] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wcs[2] = (char)((wc & 0x3f) | 0x80);
	}
	else if (wc <= 0x10ffff && MB_CUR_MAX >= 4)
	{
		wcs[0] = (char)((wc >> 18) | 0xf0);
		wcs[1] = (char)(((wc >> 12) & 0x3f) | 0x80);
		wcs[2] = (char)(((wc >> 6) & 0x3f) | 0x80);
		wcs[3] = (char)((wc & 0x3f) | 0x80);
	}
	return (wcs);
}
