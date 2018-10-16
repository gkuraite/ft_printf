/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:55:04 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/28 15:32:23 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	t;
	unsigned int	n;
	char			*str;

	i = 0;
	t = ft_strlen(s) - 1;
	n = 0;
	if (!*s)
		return ((char*)s);
	while (s[i] && ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
		i++;
	while (((s[t] == ' ') || (s[t] == '\n') || (s[t] == '\t')) && (t > i))
		t--;
	if ((str = (char *)malloc(sizeof(char) * (t - i + 2))) == NULL)
		return (NULL);
	while ((i + n) < (t + 1))
	{
		str[n] = s[i + n];
		n++;
	}
	str[n] = '\0';
	return (str);
}
