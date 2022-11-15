/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:42:52 by jdasilva          #+#    #+#             */
/*   Updated: 2022/10/01 19:55:02 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *backup, char *buff)
{
	int		read_line;
	char	*aux;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buff[read_line] = '\0';
		if (!backup)
			backup = ft_strdup ("");
		aux = backup;
		backup = ft_strjoin(aux, buff);
		free(aux);
		aux = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_extract_line(char *line)
{
	int		cont;
	char	*backup;

	cont = 0;
	while (line[cont] != '\n' && line[cont])
		cont++;
	if (line[cont] == '\0')
		return (0);
	backup = ft_substr (line, cont + 1, ft_strlen(line) - cont);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[cont + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buff;
	static char		*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(BUFFER_SIZE + 1 * (sizeof(*buff)));
	if (!buff)
		return (0);
	line = ft_read_line(fd, backup, buff);
	free(buff);
	if (!line)
	{
		free(backup);
		return (0);
	}
	backup = ft_extract_line(line);
	return (line);
}
