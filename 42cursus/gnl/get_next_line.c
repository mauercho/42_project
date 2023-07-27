/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwucho <minwucho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:33:31 by minwucho          #+#    #+#             */
/*   Updated: 2023/07/21 16:42:34 by minwucho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fd(int fd, char *backup)
{
	char	*buf;
	int		read_cnt;

	read_cnt = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (ft_strchr(backup, '\n') == 0 && read_cnt != 0)
	{
		read_cnt = read(fd, buf, BUFFER_SIZE);
		if (read_cnt == -1)
		{
			free(buf);
			free(backup);
			return (0);
		}
		buf[read_cnt] = 0;
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

static char	*line_make(char *backup)
{
	char	*tmp;
	int		i;
	int		cnt;

	i = 0;
	cnt = -1;
	if (backup[0] == 0)
		return (0);
	while (backup[i] != 0 && backup[i] != '\n')
		i++;
	if (backup[i] == 0)
		tmp = (char *)malloc(sizeof(char) * (i + 1));
	else
		tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (0);
	while (++cnt < i)
		tmp[cnt] = backup[cnt];
	if (backup[i] == '\n')
		tmp[cnt] = backup[i++];
	tmp[i] = 0;
	return (tmp);
}

static char	*reset_backup(char *backup)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	while (backup[i] != 0 && backup[i] != '\n')
		i++;
	if (backup[i] == 0)
	{
		free(backup);
		return (0);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!tmp)
		return (0);
	i++;
	while (backup[i] != 0)
		tmp[j++] = backup[i++];
	tmp[j] = 0;
	free(backup);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = read_fd(fd, backup);
	if (!backup)
	{
		free(backup);
		return (0);
	}
	line = line_make(backup);
	backup = reset_backup(backup);
	return (line);
}
