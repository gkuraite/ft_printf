/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:44:14 by gkuraite          #+#    #+#             */
/*   Updated: 2017/11/29 11:50:23 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;
	int		cpy;

	start = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start >= end)
		start = end + 1;
	if (!(str = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	cpy = 0;
	while (start <= end)
		str[cpy++] = s[start++];
	str[cpy] = '\0';
	return (str);
}
