/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:41:10 by gkuraite          #+#    #+#             */
/*   Updated: 2018/03/02 17:13:32 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		store_it(int i, int j, char *buffer, char **line)
{
	char	*tmp1;
	char	*tmp2;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp1 = ft_strnew(i - j);
	ft_strncpy(tmp1, buffer + j, (i - j));
	tmp2 = *line;
	*line = ft_strjoin(tmp2, tmp1);
	free(tmp2);
	free(tmp1);
	if (buffer[i] == '\n')
		return (i);
	else
		return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buffer[OPEN_MAX];
	int				i[OPEN_MAX];
	int				ret[OPEN_MAX];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd >= OPEN_MAX)
		return (-1);
	*line = ft_strnew(0);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strnew(BUFF_SIZE);
	if (i[fd] > 0)
	{
		i[fd] = store_it(i[fd], i[fd], buffer[fd], line);
		if (i[fd]++ != -1)
			return (1);
	}
	while (i[fd] == 0 && (ret[fd] = read(fd, buffer[fd], BUFF_SIZE)) > 0)
	{
		buffer[fd][ret[fd]] = '\0';
		i[fd] = store_it(i[fd], i[fd], buffer[fd], line);
		i[fd]++;
	}
	if (ret[fd] == -1)
		return (-1);
	return ((ret[fd] == 0 && *line[0] == 0) ? 0 : 1);
}
