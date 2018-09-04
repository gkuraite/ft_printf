/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:04:26 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/29 18:37:13 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word;

	i = 0;
	word = 0;
	if (s == NULL)
		return (0);
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			word++;
		i++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**split;

	i = 0;
	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(*split) * (ft_word(s, c) + 1))))
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c)
			j = i + 1;
		else if ((s[i] != c && s[i + 1] == c) || i == ft_strlen(s) - 1)
			split[k++] = ft_strsub(s, j, (i + 1 - j));
		i++;
	}
	split[k] = 0;
	return (split);
}
