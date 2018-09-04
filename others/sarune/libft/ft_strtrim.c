/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:44:51 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/29 18:57:16 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		m;
	int		j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (i >= j)
		i = j + 1;
	if (!(str = (char*)malloc(sizeof(*str) * (j - i + 2))))
		return (NULL);
	m = 0;
	while (i <= j)
		str[m++] = s[i++];
	str[m] = '\0';
	return (str);
}
